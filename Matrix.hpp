//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Creates a matrix which can be used for Convolutional neural network 
// Last Modified: 01/16/2023
//      Modified: Added the Index and assignment operators
#ifndef MATRIX
#define MATRIX

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

        // Array Index Operator []
        std::vector<double>& operator[](std::size_t row);
        const std::vector<double>& operator[](std::size_t row) const;

        // Assignment Operator ()
        double& operator()(std::size_t row, std::size_t col);
        const double& operator()(std::size_t row, std::size_t col) const;

        // Matrix dimensions returns m x n
        std::pair<std::size_t, std::size_t> dimensions();
        
        // Matrix size returns n x n
        std::size_t size();
};

#endif