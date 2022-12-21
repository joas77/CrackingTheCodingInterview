#include <iostream>

void swapInt(int &a, int &b);
void testSwap(int a, int b);

int main(){

    std::cout << "Testing swap integers function ..." << std::endl;

    std::cout << "case 1: a = b " << std::endl;
    testSwap(3, 3);

    std::cout << "case 2: a < b" << std::endl;
    testSwap(4, 9);

    std::cout << "case 3: a > b" << std::endl;
    testSwap(15, 11);

    return 0;
}

void swapInt(int &a, int &b){
    a = b - a; // diff
    b = b - a; // a now is diff and now b = a
    a = b + a; // a = b
}

void testSwap(int a, int b){
    std::cout << "before swap:" <<std::endl;
    std::cout << "a = " << a <<", " << "b = " << b << std::endl;

    swapInt(a, b);
    std::cout << "after swap:" <<std::endl;
    std::cout << "a = " << a <<", " << "b = " << b << std::endl;

    std::cout << "***************************" << std::endl;
}