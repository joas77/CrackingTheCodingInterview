#include <cstddef>
#include <array>

template <typename Type, std::size_t Size>
class CircularArray{
public:


private:
    std::array<Type, Size> data;
};