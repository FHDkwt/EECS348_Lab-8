// including important libraries 
#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

Matrix::Matrix(std::size_t N):size(N),data(N,std::vector<int>(N, 0))
{
    // initializing NxN matrix with zeros
}
Matrix::Matrix(const std::vector<std::vector<int>>& nums):size(nums.size()),data(nums) 
{
    // validating input is a square matrix
    for (const auto& row:nums) 
    {
        if (row.size() != size) 
        {
            throw std::invalid_argument("Input matrix must represent square matrix");
        }
    }
}

/* Implementing a function to load matrix data from a user-specified file. 
The first line of the file should contain an integer N indicating the size of the matrices, followed by two N × N matrices. 
After reading the file, print the matrices with proper formatting, such as aligned columns. N can be any valid positive integer.
*/
bool Matrix::read_from_file(const std::string& filename,Matrix& matrix1,Matrix& matrix2) 
{
    std::ifstream inFile(filename);
    if (!inFile) 
    {
        std::cerr << "Error: Unable to open file " <<filename<<std::endl;
        return false;
    }

    std::size_t N;
    inFile >> N;
    if (N <= 0) 
    {
        std::cerr << "Error: Invalid matrix size "<<N<<std::endl;
        inFile.close();
        return false;
    }

    // initializing matrices
    matrix1 = Matrix(N);
    matrix2 = Matrix(N);

    // reading first matrix
    for (std::size_t i = 0;i<N;i++) 
    {
        for (std::size_t j = 0; j<N;j++) 
        {
            int value;
            if (!(inFile>>value)) 
            {
                std::cerr << "Error: Not enough data for first matrix" <<std::endl;
                inFile.close();
                return false;
            }
            matrix1.set_value(i,j,value);
        }
    }

    // reading second matrix
    for (std::size_t i = 0;i<N;i++) 
    {
        for (std::size_t j = 0;j < N;j++) 
        {
            int value;
            if (!(inFile>>value)) 
            {
                std::cerr << "Error: Not enough data for second matrix" <<std::endl;
                inFile.close();
                return false;
            }
            matrix2.set_value(i,j,value);
        }
    }

    inFile.close();
    return true;
}

/* Implementing a function that adds two matrices and displays the resulting matrix. */
Matrix Matrix::operator+(const Matrix& rhs) const 
{
    if (size != rhs.size) 
    {
        throw std::invalid_argument("Matrices must have same size for addition");
    }

    Matrix result(size);
    for (std::size_t i = 0;i< size;i++) 
    {
        for (std::size_t j = 0;j < size;j++) 
        {
            result.set_value(i,j,data[i][j] + rhs.data[i][j]);
        }
    }
    return result;
}

/* Implementing a function that multiplies two matrices and displays the resulting matrix. */
Matrix Matrix::operator*(const Matrix& rhs) const {
    if (size != rhs.size) {
        throw std::invalid_argument("Matrices must have same size for multiplication");
    }

    Matrix result(size);
    for (std::size_t i = 0;i < size;i++) 
    {
        for (std::size_t j = 0;j < size;j++) 
        {
            int sum = 0;
            for (std::size_t k = 0;k < size;k++) 
            {
                sum += data[i][k] * rhs.data[k][j];
            }
            result.set_value(i,j,sum);
        }
    }
    return result;
}
// updateing element at position (i,j) in matrix with n
bool Matrix::set_value(std::size_t i,std::size_t j,int n) 
{
    if (i >= size || j >= size) 
    {
        return false;
    }
    data[i][j] = n;
    return true;
}
// retrieving element at position (i,j) in matrix throwing an  exception if indices are invalid
int Matrix::get_value(std::size_t i,std::size_t j) const 
{
    if (i >= size || j >= size) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data[i][j];
}
// returning size of matrix
std::size_t Matrix::get_size() const 
{
    return size;
}
/* Implementing a function to calculate and display the sum of the main diagonal elements of a matrix. */
int Matrix::sum_diagonal_major() const 
{
    int sum = 0;
    for (std::size_t i = 0;i < size;i++) 
    {
        sum += data[i][i];
    }
    return sum;
}
/* Implementing a function to calculate and display the sum of the secondary diagonal elements of a matrix. */
int Matrix::sum_diagonal_minor() const
{
    int sum = 0;
    for (std::size_t i = 0;i < size;i++) 
    {
        sum += data[i][size-1-i];
    }
    return sum;
}
/* Implementing a function that takes a matrix and two-row indices as input (with indexing starting at 0). 
If both indices are within valid bounds, swap the specified rows and output the resulting matrix. */
bool Matrix::swap_rows(std::size_t r1,std::size_t r2) 
{
    if (r1 >= size || r2 >= size) 
    {
        return false;
    }
    data[r1].swap(data[r2]);
    return true;
}
/* Implementing a function that takes a matrix and two-column indices as input (with indexing starting at 0). 
If both indices are within valid bounds, swap the specified rows and output the resulting matrix. */
bool Matrix::swap_cols(std::size_t c1,std::size_t c2) 
{
    if (c1 >= size || c2 >= size) {
        return false;
    }
    for (std::size_t i = 0;i < size;i++) {
        std::swap(data[i][c1],data[i][c2]);
    }
    return true;
}
/* Implement a function that accepts a matrix, a row index, a column index, and a new value. 
If both indices are valid (with indexing starting at 0), update the element at the specified position and display the resulting matrix. */
void Matrix::print_matrix() const 
{
    for (std::size_t i = 0;i < size;i++) 
    {
        for (std::size_t j = 0;j < size;j++) 
        {
            std::cout << std::setw(4)<<data[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
