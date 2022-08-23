#include "common.h"

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

    T& at(size_t x, size_t y)
    {
        return mData.at(x).at(y);
    };

    void rotateRigth()
    {
        // TODO: implement rotation inplace (i.e. wihtouth copy memory)
        auto tempMatrix = copy();

        for(size_t i=0; i<mSize; i++)
        {
            copyRowToColumn(i, mSize - 1 - i, tempMatrix);
        }

        mData = tempMatrix.mData;
    }

private:
    std::vector<std::vector<T>> mData;
    size_t mSize;

    void copyRowToColumn(size_t rowIndex, size_t colIndex, Matrix& dest)
    {
        for(size_t i=0; i < mData.at(rowIndex).size(); i++)
        {
            dest.at(i, colIndex) = mData.at(rowIndex).at(i); 
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
    std::cout << "B = " << std::endl;
    B.print();

    std::cout<< "Rotating B matrix..." << std::endl;
    B.rotateRigth();
    B.print();

    std::cout << "lets try with a 4x4 matrix..." <<std::endl;
    Matrix<int> C({
        {1, 2, 3, 4},
        {4, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    });

    C.print();
    C.rotateRigth();
    C.print();
    return 0;
}
