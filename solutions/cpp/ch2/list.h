#pragma once
#include <iostream>
#include <set>

template<typename T>
struct Node
{
    Node(T data)
    {
        this->data = data;
    }

    Node<T>* next{nullptr};
    T data;
};


template<typename T>
class SingleLinkedList{
public:
    SingleLinkedList();
    ~SingleLinkedList();
    void appendToTail(T data);
    void deleteNode(T data);
    void removesDuplicates();
    void print();

private:
    Node<T>* mHead{nullptr};
    
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList(){}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    Node<T>* n = mHead;

    while(n)
    {
        Node<T>* pNodeTobeDeleted = n;
        n = n->next;
        delete pNodeTobeDeleted;
    }
}

template <typename T>
void SingleLinkedList<T>::appendToTail(T data)
{
    if(mHead == nullptr)
    {
        mHead = new Node(data);
        return;
    }

    Node<T>* pEnd = new Node(data);
    Node<T>* n = mHead;
    

    while(n->next != nullptr)
    {
        n = n->next;
    }
    n->next = pEnd;
}

template <typename T>
void SingleLinkedList<T>::deleteNode(T data)
{
    Node<T>* n = mHead;
    if(n->data == data)
    {
        mHead = mHead->next; /* moved head */
        delete n;
        return;
    }

    while(n->next != nullptr)
    {
        if(n->next->data == data)
        {
            Node<T>* pNodeTobeDeleted = n->next;
            n->next = n->next->next;
            /* head didn't change */

            delete pNodeTobeDeleted;
        }
        n = n->next;
    }

}

template <typename T>
void SingleLinkedList<T>::print()
{
    Node<T>* n = mHead;

    std::cout << "[" ;
    while(n->next != nullptr)
    {
        std::cout << n->data;
        n = n->next;
        if(n->next)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// template <typename T>
// void SingleLinkedList<T>::removesDuplicates()
// {
//     std::set<T> duplicates;

//     Node<T>* n = mHead;

//     while(n->next != nullptr)
//     {
//         if(duplicates.find(n->data) != duplicates.end)
//         {
//             // data is duplicated
//             Node<T>* pNodeTobeDeleted = n;
//             n = n->next;

//         }
//         else
//         {
//             duplicates.emplace(n->data);
//             n = n->next;
//         }
//         n = n->next;
//     }
// }