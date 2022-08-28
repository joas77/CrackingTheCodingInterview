#include "common.h"

template <typename T>
class Matrix{
public:
    // TODO: assert m is an NxN array
    Matrix(const std::vector<std::vector<T>>& m):mData{m}
    {
        mRowsSize =  mData.size();
        mColsSize = mData.at(0).size();
    };

    void print()
    {
        std::cout << mData << std::endl;
    };

    Matrix copy()
    {
        return Matrix(mData);
    };

    T& at(size_t x, size_t y)
    {
        return mData.at(x).at(y);
    };

    size_t getColumnsSize() { return mColsSize; };

    size_t getRowsSize() { return mRowsSize; };

private:
    std::vector<std::vector<T>> mData;
    size_t mColsSize;
    size_t mRowsSize;
};

template <typename T>
void processZeros(const Matrix<T>& matrix)
{
    std::unordered_map<int, int> zerosPositions;

}

int main()
{
        Matrix<int> M({
        {1, 0, 3, 4},
        {4, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    });

    std::cout << "Matrix before processing 0's:" << std::endl;
    M.print();
    return 0;
}