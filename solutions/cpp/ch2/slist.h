#pragma once

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

private:
    Node<T>* mpNext = nullptr;
    T mData;
};


