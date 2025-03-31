// including header file and neccesary library 
#include "matrix.hpp"
#include <iostream>
// defining main function
int main(int argc, char *argv[]) 
{
    // prompting user for input file name
    std::string filename;
    std::cout << "Enter the input file name: ";
    std::cin >> filename;
    // reading matrices from the file
    Matrix matrix1(1), matrix2(1); // temporary initialization
    if (!Matrix::read_from_file(filename, matrix1, matrix2)) 
    {
        std::cerr << "Failed to read matrices from file. Exiting." << std::endl;
        return 1;
    }
    // displaying original matrices
    std::cout << "First matrix:" << std::endl;
    matrix1.print_matrix();
    std::cout << "Second matrix:" << std::endl;
    matrix2.print_matrix();
    // performing matrix operation - addition
    try {
        Matrix sum = matrix1 + matrix2;
        std::cout << "Result of matrix addition:" << std::endl;
        sum.print_matrix();
    } catch (const std::exception& e) {
        std::cerr << "Error during matrix addition: " << e.what() << std::endl;
        return 1;
    }
    // performing matrix operation - multiplication
    try {
        Matrix product = matrix1 * matrix2;
        std::cout << "Result of matrix multiplication:" << std::endl;
        product.print_matrix();
    } catch (const std::exception& e) {
        std::cerr << "Error during matrix multiplication: " << e.what() << std::endl;
        return 1;
    }
    // performing matrix operation - calculating and displaying diagonal sums for both matrices
    std::cout << "Diagonal sums for First matrix:" << std::endl;
    std::cout << "Main diagonal sum: " << matrix1.sum_diagonal_major() << std::endl;
    std::cout << "Secondary diagonal sum: " << matrix1.sum_diagonal_minor() << std::endl << std::endl;
    std::cout << "Diagonal sums for Second matrix:" << std::endl;
    std::cout << "Main diagonal sum: " << matrix2.sum_diagonal_major() << std::endl;
    std::cout << "Secondary diagonal sum: " << matrix2.sum_diagonal_minor() << std::endl << std::endl;

    // performing matrix operation - swapping rows
    if (matrix1.swap_rows(0, 1))
    {
        std::cout << "First matrix after swapping rows 0 and 1:" << std::endl;
        matrix1.print_matrix();
    } else 
    {
        std::cerr << "Error: Invalid row indices for swapping" << std::endl;
    }
    // performing matrix operation - swapping columns
    if (matrix1.swap_cols(0, 1)) 
    {
        std::cout << "First matrix after swapping columns 0 and 1:" << std::endl;
        matrix1.print_matrix();
    } else 
    {
        std::cerr << "Error: Invalid column indices for swapping" << std::endl;
    }

    // performing matrix operation - updating elements
    if (matrix1.set_value(0, 0, 99)) 
    {
        std::cout << "First matrix after updating element at (0,0) to 99:" << std::endl;
        matrix1.print_matrix();
    } else 
    {
        std::cerr << "Error: Invalid indices for updating element" << std::endl;
    }

    return 0;
}
