#include <string>
#include <iostream>

bool isUnique(std::string msg){
    return false;
}

int main()
{
    std::cout << "Function to determine if an string contain unique characteres\n";

    std::cout   << "abcde does contains unique characteres? "
                << isUnique("abcde") << std::endl;
    return 0;
}