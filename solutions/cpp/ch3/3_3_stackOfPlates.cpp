#include <iostream>
#include <array>
#include <vector>

template <typename T>
class SetOfStacks{
public:
    SetOfStacks(std::size_t maxHeight):
        mMaxHeight(maxHeight)
    {
        int* stack = new int[maxHeight];
    };

    void push(T data)
    {

    };

    T pop()
    {

    };



private:
    std::size_t mMaxHeight;
    std::vector<std::arra> mStacks;
};

int main()
{
    SetOfStacks<int> sStacks(10);
    return 0;
}