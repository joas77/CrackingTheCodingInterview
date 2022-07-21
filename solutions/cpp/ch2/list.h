template<typename T>
class Node
{
public:
    Node(T data)
    {
        mData = data;
    }

    Node<T>* next{nullptr};

private:
    T mData;
};


template<typename T>
class SingleLinkedList{
public:
    SingleLinkedList();
    void appendToTail(T data);

private:
    Node<T>* mHead{nullptr};
    
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList(){}

template <typename T>
void SingleLinkedList<T>::appendToTail(T data)
{
    Node<T>* pEnd = new Node(data);
    Node<T>* n = mHead;

    while(n->next != nullptr)
    {
        n = n->next;
    }
    n->next = pEnd;
}