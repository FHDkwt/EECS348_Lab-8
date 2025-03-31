#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

// including important libraries
#include <cstdint>
#include <vector>
#include <string>
// defining class "Matrix"
class Matrix {
public:
    // constructors
    Matrix(std::size_t N);
    Matrix(const std::vector<std::vector<int>>& nums);
    // read two matrices from file
    static bool read_from_file(const std::string& filename, Matrix& matrix1, Matrix& matrix2);
    // matrix operations
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;
    // getters and setters
    bool set_value(std::size_t i, std::size_t j, int n); // returns false if indices invalid
    int get_value(std::size_t i, std::size_t j) const;   // throws exception if indices invalid
    std::size_t get_size() const;
    // diagonal sums
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    // swapping operations 
    bool swap_rows(std::size_t r1, std::size_t r2);
    bool swap_cols(std::size_t c1, std::size_t c2);
    // displaying matrix
    void print_matrix() const;

private:
    std::size_t size;                    // size of matrix (N for NxN)
    std::vector<std::vector<int>> data;  // matrix data
};

#endif // __MATRIX_HPP__
