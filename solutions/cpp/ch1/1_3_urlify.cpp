#include <string>
#include "common.h"
/*
Write a method to replace all spaces in a string with '%20'.
You may assume that the string has sufficient space at the end to hold the
additional characteres, adn that you are given the "true" lenght of
the string. (Note: If implemented in Java, please use a character array so you
can perform this operation in place.)
EXAMPLE
Input:  "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"
*/

int countSpaces(const char* str, int start, int end)
{
    int spacesCount = 0;
    int i = start;
    while(str[i] && i <= end)
    {
        if(str[i]== ' ') spacesCount++;
        i++;
    }

    return spacesCount;
}


void urlify(char* str, size_t lenght)
{
    int spaces = countSpaces(str, 0, lenght-1);
    int i = lenght - 1;
    while(spaces > 0)
    {
        int newPos = i + (3*spaces - spaces);
        str[newPos] = str[i];

        if(str[i] == ' ')
        {
            // replace space by %20
            str[newPos - 2] = '%';
            str[newPos - 1] = '2';
            str[newPos] = '0';
            spaces--;
        }

        i--;
    }
}

void test(char* input, size_t lenght, int testNumber)
{
    std::cout << "**** TEST " << testNumber << " ***************" << std::endl;
    std::cout << "input: " << input << std::endl;
    urlify(input, lenght);
    std::cout << "output: " << input << std::endl;
}


int main()
{
    char inputTest[] = "Mr John Smith    ";
    
    auto spaces = countSpaces(inputTest,0,12);
    std::cout << "total spaces = " << spaces << std::endl;

    test(inputTest, 13, 1);
    char input2[] = "hola mundo  cruel         ";
    test(input2, 17, 2);
    
    return 0;
}