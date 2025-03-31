#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

Matrix::Matrix(std::size_t N) : size(N), data(N, std::vector<int>(N, 0)) {
    // Initialize an NxN matrix with zeros
}

Matrix::Matrix(const std::vector<std::vector<int>>& nums) : size(nums.size()), data(nums) {
    // Validate that the input is a square matrix
    for (const auto& row : nums) {
        if (row.size() != size) {
            throw std::invalid_argument("Input vector must represent a square matrix");
        }
    }
}

bool Matrix::read_from_file(const std::string& filename, Matrix& matrix1, Matrix& matrix2) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    std::size_t N;
    inFile >> N;
    if (N <= 0) {
        std::cerr << "Error: Invalid matrix size " << N << std::endl;
        inFile.close();
        return false;
    }

    // Initialize matrices
    matrix1 = Matrix(N);
    matrix2 = Matrix(N);

    // Read the first matrix
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            int value;
            if (!(inFile >> value)) {
                std::cerr << "Error: Not enough data for first matrix" << std::endl;
                inFile.close();
                return false;
            }
            matrix1.set_value(i, j, value);
        }
    }

    // Read the second matrix
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            int value;
            if (!(inFile >> value)) {
                std::cerr << "Error: Not enough data for second matrix" << std::endl;
                inFile.close();
                return false;
            }
            matrix2.set_value(i, j, value);
        }
    }

    inFile.close();
    return true;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (size != rhs.size) {
        throw std::invalid_argument("Matrices must have the same size for addition");
    }

    Matrix result(size);
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            result.set_value(i, j, data[i][j] + rhs.data[i][j]);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (size != rhs.size) {
        throw std::invalid_argument("Matrices must have the same size for multiplication");
    }

    Matrix result(size);
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            int sum = 0;
            for (std::size_t k = 0; k < size; k++) {
                sum += data[i][k] * rhs.data[k][j];
            }
            result.set_value(i, j, sum);
        }
    }
    return result;
}

bool Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= size || j >= size) {
        return false;
    }
    data[i][j] = n;
    return true;
}

int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= size || j >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[i][j];
}

std::size_t Matrix::get_size() const {
    return size;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; i++) {
        sum += data[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; i++) {
        sum += data[i][size - 1 - i];
    }
    return sum;
}

bool Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size) {
        return false;
    }
    data[r1].swap(data[r2]);
    return true;
}

bool Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size) {
        return false;
    }
    for (std::size_t i = 0; i < size; i++) {
        std::swap(data[i][c1], data[i][c2]);
    }
    return true;
}

void Matrix::print_matrix() const {
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            std::cout << std::setw(4) << data[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
