#include <iostream>
#include <array>
#include <vector>

template <typename T>
class ArrayStack{
public:
    ArrayStack(std::size_t size):
        mCapacity(size), mPosition(0)
    {
        mArray = new T[size];
    };

    std::size_t size(){ return mPosition; };
    std::size_t capacity() { return mCapacity; };

    void push(T data)
    {
        if(mPosition<mCapacity)
        {
            mArray[mPosition] = data;
            mPosition++;
        }
        //TODO: else throw stack overflow
    };

    T pop()
    {
        if(mPosition > 0)
        {
            mPosition--;
            return mArray[mPosition];
        }
        // TODO else throw array underflow
    };

private:
    T* mArray;
    std::size_t mCapacity;
    std::size_t mPosition;
};

template <typename T>
class SetOfStacks{
public:
    SetOfStacks(std::size_t maxHeight):
        mMaxHeight(maxHeight)
    {
        mStacks.push_back(ArrayStack<T>(maxHeight));
    };

    void push(T data)
    {
        mStacks.at(0).push(data);
    };

    T pop()
    {
        return mStacks.at(0).pop();
    };



private:
    std::size_t mMaxHeight;
    std::vector<ArrayStack<T>> mStacks;
};

int main()
{
    SetOfStacks<int> sStacks(10);

    for(std::size_t i=0; i<10; i++)
    {
        sStacks.push(i);
    }

    for(std::size_t i=0; i<10; i++)
    {
        std::cout << sStacks.pop() << std::endl;
    }
    return 0;
}