#include <cstddef>
#include <array>
#include <initializer_list>
#include <algorithm>
#include <iterator>

template <typename Type, std::size_t Size>
class CircularArray{
public:
    CircularArray(){}

    CircularArray(std::initializer_list<Type> list){
        std::copy(list.begin(), list.end(), mData.begin());
    }

    Type& operator[](const std::size_t index){
        return mData[(mStartPos + index)%size()];
    }

    std::size_t size(){
        return mData.size();
    }

    void rotate(std::size_t positions){
        mStartPos += positions % size();
    }


private:
    std::array<Type, Size> mData;
    std::size_t mStartPos = 0;
    
};