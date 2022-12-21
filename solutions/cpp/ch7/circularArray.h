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
        std::copy(list.begin(), list.end(), data.begin());
    }

    Type& operator[](const std::size_t index){
        return data[index];
    }

    std::size_t size(){
        return data.size();
    }

    void rotate(std::size_t positions){
        
    }


private:
    std::array<Type, Size> data;
};