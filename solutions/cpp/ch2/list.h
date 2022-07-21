#include <iostream>

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
    //~SingleLinkedList();
    void appendToTail(T data);
    void print();

private:
    Node<T>* mHead{nullptr};
    
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList(){}

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