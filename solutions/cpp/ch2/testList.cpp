#include <cstddef>
#include <iostream>
#include "utils.h"
#include "list.h"

int main()
{
    SingleLinkedList<int> list;

    for(size_t i=1; i<=10; i++)
    {
        list.appendToTail(i);
    }

    list.print();
    list.deleteNode(1); // deleted head
    std::cout << "List after removal first element..." << std::endl;
    list.print();
    print("list after removing 5 ...");
    list.deleteNode(5);
    list.print();

    print("list after removing 9 ...");
    list.deleteNode(9);
    list.print();

}