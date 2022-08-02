#include "common.h"
#include <ctypes>

template <typename T>
class Matrix{
public:
    // TODO: assert m is an NxN array
    Matrix(const std::vector<std::vector<T>>& m):mData{m}
    {
        mSize = mData.size();
    };

    void print()
    {
        std::cout << mData << std::endl;
    };

    Matrix copy()
    {
        return Matrix(mData);
    };

    T& at(int x, int y)
    {
        return mData.at(x).at(y);
    };

    void rotateRigth()
    {
        auto tempMatrix = copy();

        for(size_t i=0; i<mSize; i++)
        {
            copyColumnToRow(i, mSize - 1 - i, tempMatrix);
        }
    }

private:
    std::vector<std::vector<T>> mData;
    int mSize;

    void copyColumnToRow(int rowIndex, int colIndex, Matrix& dest)
    {
        for(const auto& e: mData.at(rowIndex))
        {
            
        }
    }
};

int main()
{
    std::cout << "Rotating a matrix 90 degress clockwise" << std::endl;

    Matrix<int> A({{1, 2}, {3, 4}});
    A.print();

    auto B = A.copy();

    std::cout << "if I change matrix A, B should't be affected..." << std::endl;

    A.at(1,1) = 10;
    A.print();
    B.print();
    return 0;
}
