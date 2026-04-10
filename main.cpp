#include "Dictionary.h"

int main() {
  Dictionary dict1("English-Ukrainian");
  dict1.addWord({"apple", "яблуко"});
  dict1.addWord({"book", "книга"});
  dict1.addWord({"cat", "кіт"});

  Dictionary dict2("English-Ukrainian-Extra");
  dict2.addWord({"dog", "собака"});
  dict2.addWord({"book", "книга"});
  dict2.addWord({"sun", "сонце"});

  std::cout << "=== Словник 1 ===\n";
  dict1.print();
  std::cout << "\n=== Словник 2 ===\n";
  dict2.print();

  std::cout << "\n=== Об’єднання ===\n";
  Dictionary unionDict = dict1 + dict2;
  unionDict.print();

  std::cout << "\n=== Перетин ===\n";
  Dictionary interDict = dict1 * dict2;
  interDict.print();

  std::cout << "\n=== Різниця ===\n";
  Dictionary diffDict = dict1 - dict2;
  diffDict.print();

  std::cout << "\n=== Пошук слова 'cat' ===\n";
  WordCard found = dict1["cat"];
  if (!found.foreign.empty())
    std::cout << found.foreign << " -> " << found.translation << "\n";

  return 0;
}
