#include <cstddef>
#include "list.h"

int main()
{
    SingleLinkedList<int> list;

    for(size_t i=1; i<=10; i++)
    {
        list.appendToTail(i);
    }

    //list.print();

}