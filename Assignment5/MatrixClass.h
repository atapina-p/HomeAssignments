/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 5
*/

#ifndef MATRIX
#define MATRIX


#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>


template <typename T>
class MatrixClass
{
public:
    // Constructor
    MatrixClass(std::size_t rows, std::size_t cols): _rows(rows), _cols(cols)
    {
        if (_rows == 0 || _cols == 0)
        {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
        if (_rows > 0 && _cols > 0)
        {
            _data.resize(_rows, std::vector<T>(_cols, T()));
        }

    };

    MatrixClass(std::size_t rows, std::size_t cols, const std::vector<std::vector<T>> data): _rows(rows), _cols(cols)
    {
        if (rows == 0 || cols == 0)
        {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
        else if (data.size() != rows || (rows > 0 && data[0].size() != cols))
        {
            throw std::invalid_argument("Invalid initializer dimensions");
        }
        else _data = data;
    };

    ~MatrixClass() {}; // Destructor

    // Getters
    std::size_t getRows() const
    {
        return _rows;
    }

    std::size_t getCols() const
    {
        return _cols;
    }

    T& operator()(std::size_t row, std::size_t col)
    {
        if (row >= _rows || col >= _cols)
        {
            throw std::out_of_range("Matrix index out of range");
        }
        return _data[row][col];
    }

    const T& operator()(std::size_t row, std::size_t col) const
    {
        if (row >= _rows || col >= _cols)
        {
            throw std::out_of_range("Matrix index out of range");
        }
        return _data[row][col];
    }

    // Multiplication by a scalar
    MatrixClass<T> operator*(const T& scalar) const
    {
        MatrixClass<T> result(_rows, _cols);
        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < _cols; ++j)
            {
                result(i, j) = _data[i][j] * scalar;
            }
        }
        return result;
    }

    MatrixClass<T>& operator*=(const T& scalar)
    {
        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < _cols; ++j)
            {
                _data[i][j] *= scalar;
            }
        }
        return *this;
    }

    // Addition
    MatrixClass<T> operator+(const MatrixClass<T>& other) const
    {
        if (_rows != other._rows || _cols != other._cols)
        {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        MatrixClass<T> result(_rows, _cols);
        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < _cols; ++j)
            {
                result(i, j) = _data[i][j] + other(i, j);
            }
        }
        return result;
    }

    MatrixClass<T>& operator+=(const MatrixClass<T>& other)
    {
        if (_rows != other._rows || _cols != other._cols)
        {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < _cols; ++j)
            {
                _data[i][j] += other(i, j);
            }
        }
        return *this;
    }

    // Matrix multiplication
    MatrixClass<T> operator*(const MatrixClass<T>& other) const
    {
        if (_cols != other._rows)
        {
            throw std::invalid_argument(
                "Number of columns in first matrix must equal number of rows in second matrix"
            );
        }

        MatrixClass<T> result(_rows, other._cols);
        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < other._cols; ++j)
            {
                T sum = T();
                for (std::size_t k = 0; k < _cols; ++k)
                {
                    sum += _data[i][k] * other(k, j);
                }
                result(i, j) = sum;
            }
        }
        return result;
    }

    // Transposition
    MatrixClass<T> transpose() const
    {
        MatrixClass<T> result(_cols, _rows);
        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < _cols; ++j)
            {
                result(j, i) = _data[i][j];
            }
        }
        return result;
    }

    // Equality
    bool operator==(const MatrixClass<T>& other) const
    {
        if (_rows != other._rows || _cols != other._cols)
        {
            return false;
        }

        for (std::size_t i = 0; i < _rows; ++i)
        {
            for (std::size_t j = 0; j < _cols; ++j)
            {
                if (_data[i][j] != other(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const MatrixClass<T>& other) const
    {
        return !(*this == other);
    }
private:
    std::vector<std::vector<T>> _data;
    std::size_t _rows;
    std::size_t _cols;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MatrixClass<T>& matrix)
{
    for (std::size_t i = 0; i < matrix.getRows(); ++i)
    {
        for (std::size_t j = 0; j < matrix.getCols(); ++j)
        {
            os << std::setw(6) << matrix(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}


#endif
