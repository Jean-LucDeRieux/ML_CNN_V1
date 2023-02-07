//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Non-member functions for matrix operations
// Last Modified: 02/07/2023
//      Modified: Changed inputs for maxPool and avgPool to include output matrix desired size f and segment steps s

#ifndef MATRIXTOOLS_HPP
#define MATRIXTOOLS_HPP

#include "Matrix.hpp"
#include <cstddef> // Needed for size_t
#include <utility> // Needed for pair
#include <cmath>   // Needed for finding the nxn size of matrix

namespace  matrix_tools{

    // Returns a 2D matrix segment of the 2D input matrix
    Matrix segment(const Matrix& mtrx, const std::size_t& staRow, const std::size_t& staCol, const std::size_t& endRow, const std::size_t& endCol);

    // Multipies then sums the 2D inputs matrices and returns a double. Inputs must have same dimensions.
    double multSum(const Matrix& mat1, const Matrix& mat2);

    // Returns the average value of the input matrix
    double avg(const Matrix& mtrx);

    // Returns the max value of the input matrix
    double max(const Matrix& mtrx);

    // Convolution of two 2D matrices and returns a 2D feature Matrix
    Matrix conv(const Matrix& mtrx, const Matrix& kernal);

    // Takes a 2D input matrix and runs the Max Pooling algorithm to downscale the matrix
    Matrix maxPool(const Matrix& mtrx, std::size_t f, std::size_t s);

    // Takes an input matrix and runs the Max Pooling algorithm to downscale the matrix
    Matrix avgPool(const Matrix& mtrx, std::size_t f, std::size_t s);
}

#endif //MATRIXTOOLS_HPP