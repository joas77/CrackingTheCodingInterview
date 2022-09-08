#include <iostream>
#include "slist.h"

int main()
{

    std::cout << "Testing node based single linked list ..." << std::endl;

    Node<int> head = Node(0);

    for(std::size_t i=1; i<=10; i++)
    {
        head.appendToTail(i);
    }

    return 0;
}