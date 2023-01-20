//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Non-member functions for matrix operations
// Last Modified: 01/16/2023
//      Modified: Fixed toString by setting it to const
#ifndef MT
#define MT

#include "Matrix.hpp"
#include <cstddef> // Needed for size_t
#include <utility> // Needed for pair
#include <cmath>   // Needed for finding the nxn size of matrix

// Returns segment from matrix
Matrix segment(Matrix input, std::size_t strRow, std::size_t strCol,
                           std::size_t endRow, std::size_t endCol);

// Multipies then sums, input 2 matrices, returns scaler
double multSum(Matrix mat1, Matrix mat2);

// Convolution, input 2 matrices, returns feature Matrix
Matrix conv(Matrix mtrx, Matrix kernal);

// Max Pooling, input 2 matrices, returns new Matrix
Matrix maxPool(Matrix mat1, Matrix mat2);

// Avg Pooling, input 2 matrices, returns new Matrix
Matrix avgPool(Matrix mat1, Matrix mat2);

#endif