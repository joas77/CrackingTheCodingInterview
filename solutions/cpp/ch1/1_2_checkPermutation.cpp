#include "common.h"

std::unordered_map<char, int> wordToCharFreq(const std::string& word)
{
    std::unordered_map<char, int> charFreqWord;

    for(char c: word)
    {
       if (charFreqWord.find(c)== charFreqWord.end())
       {
            charFreqWord[c] = 1;
       }
       else
       {
            charFreqWord[c]++;
       }
    }

    return charFreqWord;
}

bool isPermutation(const std::string& word, const std::string& permutation)
{
    if(word.size() != permutation.size()) return false;

    auto charFreqWord = wordToCharFreq(word);
    auto charFreqPermutation = wordToCharFreq(permutation);

    return charFreqPermutation == charFreqWord;
}

int main()
{
    std::cout << "Function to decide if given two strings one is a permutatiion of" << std::endl
        << " the other" << std::endl;

    std::vector<std::string> words{
        "hola",
        "aloh",
        "ahlo",
        "loha",
        "aaaa",
        "mundo"

        };

    for(auto& w: words)
    {
        std::cout << w << " is permutation of " << "hola? " << (isPermutation("hola", w) ? "YES" : "NO") << std::endl;
    }

    return 0;
}