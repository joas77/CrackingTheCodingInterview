#include <iostream>
#include <string_view>
#include <array>
#include <unordered_map>

bool isPalindromePermutation(std::string_view text);

int main(){
    std::array<std::string, 5> texts{{
        "hola mundo",
        "atlas salta",
        "Tact Coa",
        "Anita la tina lavava",
        "Julio"
    }};

    for(auto& text: texts){
        std::cout << "'" << text << "' is a permutation of a palindrome ? " <<
            isPalindromePermutation(text) << std::endl; 
    }
    return 0;
}

bool isPalindromePermutation(std::string_view text){
    std::unordered_map<char, int> charFrequencies;
    for(auto c: text){
        if(!std::isalpha(c)) continue; 

        auto cLow = static_cast<char>(std::tolower(static_cast<char>(c)));
        if(charFrequencies.find(cLow) != charFrequencies.end()){
            charFrequencies.at(cLow)++;
        }
        else{
            charFrequencies.insert(std::make_pair(cLow, 1));
        }
    }

    // count odd number of characters
    int oddCount = 0;

    for(auto const& [c, cCount]: charFrequencies){
        if(cCount%2 != 0) oddCount++;
    }
    return oddCount <= 1;
}