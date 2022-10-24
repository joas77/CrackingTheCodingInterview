#include "hashTable.h"
#include <string>

int main() {
    HashTable<std::string, int> dict;

    dict.add("monday", 1);
    dict.add("tuesday", 2);
    dict.add("wednesday", 3);
    dict.print();

    HashTable<char, int> dictAlphabet;
    

    return 0;
}