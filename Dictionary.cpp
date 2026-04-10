#include "Dictionary.h"

bool Dictionary::exists(const std::string &foreign) const {
  for (const auto &w : words) {
    if (w.foreign == foreign)
      return true;
  }
  return false;
}

void Dictionary::setName(const std::string &name) { dictName = name; }

std::string Dictionary::getName() const { return dictName; }

void Dictionary::addWord(const WordCard &card) {
  if (size >= MAX_SIZE) {
    std::cerr << "Помилка: перевищено допустимий розмір масиву!" << std::endl;
    return;
  }
  if (exists(card.foreign)) {
    std::cerr << "Помилка: слово вже існує у словнику!" << std::endl;
    return;
  }
  words.push_back(card);
  size = words.size();
}

void Dictionary::removeWord(const std::string &foreign) {
  for (auto it = words.begin(); it != words.end(); ++it) {
    if (it->foreign == foreign) {
      words.erase(it);
      size = words.size();
      return;
    }
  }
  std::cerr << "Помилка: слово не знайдено!" << std::endl;
}

WordCard Dictionary::search(const std::string &foreign) const {
  for (const auto &w : words) {
    if (w.foreign == foreign)
      return w;
  }
  std::cerr << "Помилка: слово не знайдено!" << std::endl;
  return {"", ""};
}

Dictionary Dictionary::operator+(const Dictionary &other) const {
  Dictionary result(dictName + "_union_" + other.dictName);
  result.words = words;
  for (const auto &w : other.words) {
    if (!result.exists(w.foreign)) {
      if (result.words.size() < MAX_SIZE) {
        result.words.push_back(w);
      } else {
        std::cerr << "Помилка: перевищено MAX_SIZE при об'єднанні!"
                  << std::endl;
        break;
      }
    }
  }
  result.size = result.words.size();
  return result;
}

Dictionary Dictionary::operator*(const Dictionary &other) const {
  Dictionary result(dictName + "_intersection_" + other.dictName);
  for (const auto &w : words) {
    if (other.exists(w.foreign))
      result.words.push_back(w);
  }
  result.size = result.words.size();
  return result;
}

Dictionary Dictionary::operator-(const Dictionary &other) const {
  Dictionary result(dictName + "_difference_" + other.dictName);
  for (const auto &w : words) {
    if (!other.exists(w.foreign))
      result.words.push_back(w);
  }
  result.size = result.words.size();
  return result;
}

WordCard Dictionary::operator[](const std::string &foreign) const {
  return search(foreign);
}

void Dictionary::print() const {
  std::cout << "Словник: " << dictName << " (кількість слів: " << size << ")\n";
  for (const auto &w : words) {
    std::cout << w.foreign << " -> " << w.translation << "\n";
  }
}
