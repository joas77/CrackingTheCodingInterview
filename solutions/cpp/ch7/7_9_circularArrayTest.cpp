#include "circularArray.h"

int main()
{
    CircularArray<int, 10> circArr;

    for(std::size_t i=0; i<10; i++){
        circArr[i] = 2*i;    
    }
    return 0;
}