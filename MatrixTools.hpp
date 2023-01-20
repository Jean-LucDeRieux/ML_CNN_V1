//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Non-member functions for matrix operations
// Last Modified: 01/20/2023
//      Modified: Changed #define Guard and added namespace meet Google C++ Style Guide 

#ifndef MATRIXTOOLS_HPP
#define MATRIXTOOLS_HPP

#include "Matrix.hpp"
#include <cstddef> // Needed for size_t
#include <utility> // Needed for pair
#include <cmath>   // Needed for finding the nxn size of matrix

namespace  matrix_tools{

    // Returns a segment of the input matrix
    Matrix segment(const Matrix& input, std::size_t strRow, std::size_t strCol, std::size_t endRow, std::size_t endCol);

    // Multipies then sums the inputs matrices and returns a double
    double multSum(const Matrix& mat1, const Matrix& mat2);

    // Convolves two matrices and returns a feature Matrix
    Matrix conv(const Matrix& mtrx, const Matrix& kernal);

    // Takes an input matrix and runs the Max Pooling algorithm to downscale the matrix
    Matrix maxPool(const Matrix& mat1, const Matrix& mat2);

    // Takes an input matrix and runs the Max Pooling algorithm to downscale the matrix
    Matrix avgPool(const Matrix& mat1, const Matrix& mat2);
}

#endif //MATRIXTOOLS_HPP