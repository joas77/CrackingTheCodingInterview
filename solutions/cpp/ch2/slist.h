#pragma once
#include <iostream>

template <typename T>
class Node{
public:
    Node(T data)
    {
        mData = data;
    };

    void appendToTail(T data)
    {
        Node<T>* pEnd = new Node(data);
        Node<T>* n = this;

        while(n->mpNext)
        {
            n = n->mpNext;
        }
        n->mpNext = pEnd;
    };

    const T& getData() const{
        return mData;
    }

    const Node* getNext() const{
        return mpNext;
    }

private:
    Node<T>* mpNext = nullptr;
    T mData;
};

template <typename T>
Node<T>* deleteNode(const Node<T>* head, T data){
    auto n = head;
    if(n->data == data){
        return head->next; // moved head
        delete n;
    }

    while(n->next){
        if(n->next->data == data){
            n->next = n->next->next;
            return head; /* head didn' change */
        }
        n = n->next;
    }
    return head; // data not found
}

template <typename T>
void printSingleLinkedList(const Node<T>& head){
    auto node = head;
    do{
        std::cout << node.getData() << " ";
        node = *node.getNext();
    }while(node.getNext());

    std::cout << node.getData() << " ";
    std::cout << std::endl;
}

