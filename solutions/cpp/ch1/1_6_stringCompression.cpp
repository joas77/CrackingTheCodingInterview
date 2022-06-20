#include <string>
#include <vector>
#include <iostream>

std::string compressString(const std::string& msg)
{
    std::string compressedStr;
    
    int count = 1;
    for(size_t i = 1; i<msg.size(); i++)
    {
        if(msg[i] == msg[i-1])
        {
            count++;
        }
        else
        {
            compressedStr += msg[i-1] + std::to_string(count);
            count = 1;
        }
    }
    compressedStr += msg[msg.size()-1] + std::to_string(count);

    return compressedStr.size() < msg.size()? compressedStr : msg;
}

int main()
{
    std::cout << "Function to compress a string \n";

    std::vector<std::string> testMsgs{
        "aabcccccaaa",
        "aa",
        "abc",
        "a"
        };

    for(const auto& msg: testMsgs)
    {
        std::cout << msg << " compressed: " << compressString(msg) << std::endl;
    }
    return 0;
}