#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <string>

class Matrix {
public:
    // Constructors
    Matrix(std::size_t N);
    Matrix(const std::vector<std::vector<int>>& nums);

    // Read two matrices from a file (returns false if reading fails)
    static bool read_from_file(const std::string& filename, Matrix& matrix1, Matrix& matrix2);

    // Matrix operations
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;

    // Getters and setters
    bool set_value(std::size_t i, std::size_t j, int n); // Returns false if indices are invalid
    int get_value(std::size_t i, std::size_t j) const;   // Throws exception if indices are invalid
    std::size_t get_size() const;

    // Diagonal sums
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;

    // Swap operations (return false if indices are invalid)
    bool swap_rows(std::size_t r1, std::size_t r2);
    bool swap_cols(std::size_t c1, std::size_t c2);

    // Display the matrix
    void print_matrix() const;

private:
    std::size_t size;                    // Size of the matrix (N for NxN)
    std::vector<std::vector<int>> data;  // Matrix data
};

#endif // __MATRIX_HPP__
