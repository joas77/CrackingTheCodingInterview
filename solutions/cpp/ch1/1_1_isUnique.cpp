#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

bool isUnique(const std::string& msg){
    std::unordered_map<char, int> charCount;

    for(char c: msg)
    {
        if(charCount.find(c) != charCount.end())
        {
            charCount[c]++;
        }
        else
        {
            charCount[c] = 1;
        }
    }

    for(auto [character, count]: charCount)
    {
        if(count>1) return false;
    }

    return true;
}

bool test_isunique(const std::string& msg)
{
    bool result = isUnique(msg);
    std::cout   <<"'"<< msg << "'" << " does contains unique characteres? "
                << (result ? "true" : "false") << std::endl;

    return result;
}

int main()
{
    std::cout << "Function to determine if an string contain unique characteres\n";

    std::vector<std::string> testMsgs{
        "a",
        "aa",
        "abc",
        "monsse",
        "julio"
        };

    for(const auto& msg: testMsgs)
    {
        test_isunique(msg);
    }
    return 0;
}