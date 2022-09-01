#include "common.h"

template <typename T>
class Matrix{
public:

    
    Matrix(const std::vector<std::vector<T>>& m):mData{m}
    {
        mRowsSize =  mData.size();
        mColsSize = mData.at(0).size();
    };

    auto begin() { return mData.begin(); };
    auto end() {return mData.end(); };

    void print()
    {
        std::cout << mData << std::endl;
    };

    Matrix copy()
    {
        return Matrix(mData);
    };

    T& at(std::size_t x, std::size_t y)
    {
        return mData.at(y).at(x);
    };

    std::size_t getColumnsSize() { return mColsSize; };

    std::size_t getRowsSize() { return mRowsSize; };

private:
    std::vector<std::vector<T>> mData;
    std::size_t mColsSize;
    std::size_t mRowsSize;
};

struct Point{
    int x;
    int y;
};

template <typename T>
void processZeros(Matrix<T>& matrix)
{
    std::vector<Point> zeroPositions;

    for(std::size_t row=0; row < matrix.getRowsSize(); row++)
    {
        for(std::size_t col = 0; col < matrix.getColumnsSize(); col++)
        {
            if(matrix.at(row, col) == 0)
            {
                zeroPositions.push_back(Point{row, col});
            }
        }
    }

    for(const auto& p: zeroPositions)
    {
        std::cout<< "zero at position (" << p.x << ", " << p.y << ")" << std::endl;
        setZerosRowMatrix(matrix, p.y);
        setZerosColMatrix(matrix, p.x);
    }

}

template <typename T>
void setZerosRowMatrix(Matrix<T>& matrix, std::size_t rowIndex)
{
    for(std::size_t i = 0; i < matrix.getColumnsSize(); i++)
    {
        matrix.at(i, rowIndex) = 0;
    }
}

template <typename T>
void setZerosColMatrix(Matrix<T>& matrix, std::size_t colIndex)
{
    for(std::size_t i = 0; i < matrix.getRowsSize(); i++)
    {
        matrix.at(colIndex, i) = 0;
    }
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
    std::cout << "iterating in rows"  << std::endl;


    std::cout << "Iterating matrix in iterator old way" << std::endl;
    for(auto it= M.begin(); it!=M.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    processZeros(M);
    std::cout << "Iterating matrix with for each way" << std::endl;
    for(const auto& row: M)
    {
        std::cout << row << std::endl;
    }
    
    
    return 0;
}