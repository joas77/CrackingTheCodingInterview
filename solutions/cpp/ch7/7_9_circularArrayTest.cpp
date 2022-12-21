#include "circularArray.h"
#include <iostream>

template<typename T, std::size_t Size>
void testCircArrayConstruction(CircularArray<T, Size>& circArr){
    std::cout << "*******************************" << std::endl;
    std::cout << "Circular Array: [";
    for(std::size_t i=0; i<circArr.size(); i++){
       std::cout <<  circArr[i] <<", "; 
    }
    std::cout << "]" << std::endl;

    std::cout << "circArr.size() = " << circArr.size() << std::endl;
    std::cout << "*******************************" << std::endl;
}

int main()
{
    CircularArray<int, 10> circArr;

    for(std::size_t i=0; i<10; i++){
        circArr[i] = 2*i;    
    }

    std::cout << "Testing operator [] ..." <<std::endl;
    testCircArrayConstruction(circArr);
    // Testing initializer list
    CircularArray<int, 10> initListArr{{1,2,3,4,5,6,7,8,9,10}};
    testCircArrayConstruction(initListArr);

    std::cout << "Testing rotate method..." << std::endl;
    for(std::size_t i=0; i<initListArr.size(); i++){
        std::cout << "rotating " << i << " positions..." << std::endl;
        initListArr.rotate(i);
        testCircArrayConstruction(initListArr);
    }

    return 0;
}
