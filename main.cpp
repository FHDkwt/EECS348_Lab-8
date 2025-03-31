#include "matrix.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    // Prompt user for the input file name
    std::string filename;
    std::cout << "Enter the input file name: ";
    std::cin >> filename;

    // Read the matrices from the file
    Matrix matrix1(1), matrix2(1); // Temporary initialization, will be overwritten
    if (!Matrix::read_from_file(filename, matrix1, matrix2)) {
        std::cerr << "Failed to read matrices from file. Exiting." << std::endl;
        return 1;
    }

    // Display the original matrices
    std::cout << "First matrix:" << std::endl;
    matrix1.print_matrix();

    std::cout << "Second matrix:" << std::endl;
    matrix2.print_matrix();

    // Perform matrix addition
    try {
        Matrix sum = matrix1 + matrix2;
        std::cout << "Result of matrix addition:" << std::endl;
        sum.print_matrix();
    } catch (const std::exception& e) {
        std::cerr << "Error during matrix addition: " << e.what() << std::endl;
        return 1;
    }

    // Perform matrix multiplication
    try {
        Matrix product = matrix1 * matrix2;
        std::cout << "Result of matrix multiplication:" << std::endl;
        product.print_matrix();
    } catch (const std::exception& e) {
        std::cerr << "Error during matrix multiplication: " << e.what() << std::endl;
        return 1;
    }

    // Calculate and display diagonal sums for both matrices
    std::cout << "Diagonal sums for First matrix:" << std::endl;
    std::cout << "Main diagonal sum: " << matrix1.sum_diagonal_major() << std::endl;
    std::cout << "Secondary diagonal sum: " << matrix1.sum_diagonal_minor() << std::endl << std::endl;

    std::cout << "Diagonal sums for Second matrix:" << std::endl;
    std::cout << "Main diagonal sum: " << matrix2.sum_diagonal_major() << std::endl;
    std::cout << "Secondary diagonal sum: " << matrix2.sum_diagonal_minor() << std::endl << std::endl;

    // Swap rows (example: swap rows 0 and 1 in the first matrix)
    if (matrix1.swap_rows(0, 1)) {
        std::cout << "First matrix after swapping rows 0 and 1:" << std::endl;
        matrix1.print_matrix();
    } else {
        std::cerr << "Error: Invalid row indices for swapping" << std::endl;
    }

    // Swap columns (example: swap columns 0 and 1 in the first matrix)
    if (matrix1.swap_cols(0, 1)) {
        std::cout << "First matrix after swapping columns 0 and 1:" << std::endl;
        matrix1.print_matrix();
    } else {
        std::cerr << "Error: Invalid column indices for swapping" << std::endl;
    }

    // Update element (example: update element at (0,0) in the first matrix to 99)
    if (matrix1.set_value(0, 0, 99)) {
        std::cout << "First matrix after updating element at (0,0) to 99:" << std::endl;
        matrix1.print_matrix();
    } else {
        std::cerr << "Error: Invalid indices for updating element" << std::endl;
    }

    return 0;
}
