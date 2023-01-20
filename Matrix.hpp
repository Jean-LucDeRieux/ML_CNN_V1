//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Creates a matrix object which can be used for convolution
// Last Modified: 01/20/2023
//      Modified: Changed #define Guard and added Move/Copy operations to meet Google C++ Style Guide 

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef> // Needed for size_t
#include <utility> // Needed for pair
#include <vector>  // Needed for creating the matrix ()
#include <cassert> // Needed for assertions

class Matrix {
    private:
        // m x n is rows x columns
        std::size_t m;
        std::size_t n;

        // The matrix is a vector full of vectors double
        std::vector<std::vector<double>> matrix;

    public:

        // Constructor for a matrix with rows and cols
        Matrix(std::size_t rows, std::size_t cols);

        // Move Operations
        Matrix(Matrix&& other) = default;
        Matrix& operator=(Matrix&& other) = default;

        // Copy Operations
        Matrix(const Matrix&) = default;
        Matrix& operator=(const Matrix&) = default;

        // Array Index Operator []
        std::vector<double>& operator[](std::size_t row);
        const std::vector<double>& operator[](std::size_t row) const;

        // Assignment Operator ()
        double& operator()(std::size_t row, std::size_t col);
        const double& operator()(std::size_t row, std::size_t col) const;

        // Matrix dimensions returns m x n
        std::pair<std::size_t, std::size_t> dimensions() const;
        
        // Matrix size returns n x n
        std::size_t size() const;
};

#endif // MATRIX_HPP