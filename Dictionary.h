#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>

// Базовий клас Array
class Array {
protected:
  static const int MAX_SIZE = 256;
  int size;

public:
  Array(int s = 0) : size(s) {
    if (s < 0 || s > MAX_SIZE) {
      std::cerr << "Помилка: недопустимий розмір масиву!" << std::endl;
      exit(1);
    }
  }
  int getSize() const { return size; }
};

// Структура картки слова
struct WordCard {
  std::string foreign;
  std::string translation;
};

// Клас Dictionary
class Dictionary : public Array {
private:
  std::string dictName;
  std::vector<WordCard> words;

  bool exists(const std::string &foreign) const;

public:
  Dictionary(const std::string &name = "Unnamed") : Array(0), dictName(name) {}

  void setName(const std::string &name);
  std::string getName() const;

  void addWord(const WordCard &card);
  void removeWord(const std::string &foreign);
  WordCard search(const std::string &foreign) const;

  Dictionary operator+(const Dictionary &other) const; // об’єднання
  Dictionary operator*(const Dictionary &other) const; // перетин
  Dictionary operator-(const Dictionary &other) const; // різниця

  WordCard operator[](const std::string &foreign) const; // індексація по слову

  void print() const;
};

#endif
