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
    void appendToTail(T data);
    
};