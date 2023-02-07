//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Function declartions for matrix tools created to manipulate matrix objects
// Last Modified: 01/23/2023
//      Modified: Added Avg and Max pooling

#include "MatrixTools.hpp"

namespace matrix_tools {

    Matrix segment(const Matrix& mtrx, const std::size_t& staRow, const std::size_t& staCol, const std::size_t& endRow, const std::size_t& endCol){

        // Creating the output matrix and adding +1 because size starts at 1 and not 0
        Matrix output(endRow-staRow+1,endCol-staCol+1);

        // Declaring the placement of the output indices
        std::size_t rowOutput = 0;
        std::size_t colOutput = 0;

        // Cycling through rows of the input matrix
        for(std::size_t row = staRow; row <= endRow; row++){

            // Cycling through cols of the input matrix
            for(std::size_t col = staCol; col <= endCol; col++){

                // Taking segment from input and plugging it into output
                output[rowOutput][colOutput] = mtrx[row][col];

                // Incrementing to change cols for output
                colOutput++;
            }

            // Setting cols back to 0 to restart cycle
            colOutput = 0;

            // Incrementing to change to next row for output
            rowOutput++;
        }

        // Returning output matrix
        return output;
    }

    double multSum(const Matrix& mat1, const Matrix& mat2){

        // Retrievng the dimensions of the inputs
        std::pair<size_t, size_t> dim_mat1 = mat1.dimensions();
        std::pair<size_t, size_t> dim_mat2 = mat2.dimensions();

        // Running sum
        double sum = 0;

        // Cycling through the rows of the input matrix
        for(std::size_t row = 0; row < dim_mat1.first;row++){

            // Cycling through the cols of the input matrix
            for(std::size_t col = 0; col < dim_mat1.second;col++){

                // Multipling then summing the inputs
                sum += mat1[row][col]*mat2[row][col];
            }
        }

        // Returning the sum
        return sum;
    }

    double avg(const Matrix& mtrx){

        // Retrievng the dimensions of the inputs
        std::pair<size_t, size_t> dim_mtrx = mtrx.dimensions();

        // Running sum
        double sum = 0;
        double count = 0;

        // Cycling through the rows of the input matrix
        for(std::size_t row = 0; row < dim_mtrx.first;row++){

            // Cycling through the cols of the input matrix
            for(std::size_t col = 0; col < dim_mtrx.second;col++){

                // Sums each input of the matrix
                sum += mtrx[row][col];
                count++;
            }
        }

        // Returning the sum
        return (sum/count);
    }

    double max(const Matrix& mtrx){

        // Retrievng the dimensions of the inputs
        std::pair<size_t, size_t> dim_mtrx = mtrx.dimensions();

        // Running Max
        double max = 0;

        // Cycling through the rows of the input matrix
        for(std::size_t row = 0; row < dim_mtrx.first;row++){

            // Cycling through the cols of the input matrix
            for(std::size_t col = 0; col < dim_mtrx.second;col++){

                // Sums each input of the matrix
                if (max <  mtrx[row][col]){
                    max = mtrx[row][col];
                }
                
            }
        }

        // Returning the sum
        return max;
    }
    
    Matrix conv(const Matrix& mtrx, const Matrix& kernal){

        // If the input image matrix is of size “n x n” and if the kernel size 
        //      “f x f” and we have defined padding as p then
        //      Then the size of the output image matrix will be n + 2p -f +1
        std::size_t n = std::sqrt(mtrx.size())- std::sqrt(kernal.size()) + 1;

        // Output matrix declartion
        Matrix output(n,n);

        // Because idex starts at 0 and not 1.
        n--;        

        // Finding the kernal dimensions for proper placement of the segment
        std::pair<std::size_t, std::size_t> dimKern = kernal.dimensions();
        std::size_t kernRows = dimKern.first-1;
        std::size_t kernCols = dimKern.second-1;

        // m x n = rows x columns
        std::size_t staCol = 0; // Always 0 + i
        std::size_t staRow = 0; // Always 0 + i
        std::size_t endCol = 0; // Always n + i
        std::size_t endRow = 0; // Always m + i
        

        // Cycle through rows
        for(std::size_t row = 0; row <= n; row++){

            // startRow will increment 1+ every iteration
            staRow = row;

            // endRow will always start at m_kernal and end at mtrx size m
            endRow = kernRows + row;

            // Cycle through cols
            for(std::size_t col = 0; col <= n; col++){
                // startCol will always start at 0 after every iteration
                staCol = 0 + col;

                // endCol will always start at n_kernal and end at mtrx size n
                endCol = kernCols + col;

                // Takes segment from (x1,y1) and (x2,y2) and runs multSum to make it more efficient
                output[row][col] = multSum(segment(mtrx,staRow,staCol,endRow,endCol),kernal);
            }
        }

        return output;
    }

    Matrix maxPool(const Matrix& mtrx, std::size_t f, std::size_t s){
        
        // If the input image matrix is of size “n x n” and if the output size 
        //      “f x f” and we have defined padding as p then
        //      Then the size of the output image matrix will be [(n + 2p -f)/s + 1]
        std::size_t n = s;

        // Creates a new matrix based off of the downscaled matrix
        Matrix output(f, f);

        // m x n = rows x columns
        // n-segments
        std::size_t staCol = 0;
        std::size_t staRow = 0; 
        std::size_t endCol = s-1;
        std::size_t endRow = s-1; 

        for (std::size_t row = 0; row < f; row++) {
            for (std::size_t col = 0; col < f; col++) {

                // Takes a segment from (x1, y1) and (x2, y2) and runs max to find the maximum value
                output[row][col] = max(segment(mtrx, staRow, staCol, endRow, endCol));

                // If the end column goes past the matrix size, move the segment down one segment-n and reset the column
                if (endCol >= mtrx.dimensions().second-1) {
                    staRow += s;
                    endRow += s;
                    staCol = 0;
                    endCol = s-1;
                }
                else{

                    // Move the n-segment to the right
                    staCol += s;
                    endCol += s;
                }

            }
        }

        return output;
    }

    Matrix avgPool(const Matrix& mtrx, std::size_t f, std::size_t s){
        
        // If the input image matrix is of size “n x n” and if the output size 
        //      “f x f” and we have defined padding as p then
        //      Then the size of the output image matrix will be [(n + 2p -f)/s + 1]
        std::size_t n = s;

        // Creates a new matrix based off of the downscaled matrix
        Matrix output(f, f);

        // m x n = rows x columns
        // n-segments
        std::size_t staCol = 0;
        std::size_t staRow = 0;
        std::size_t endCol = s-1;
        std::size_t endRow = s-1; 

        for (std::size_t row = 0; row < f; row++) {
            for (std::size_t col = 0; col < f; col++) {

                // Takes a segment from (x1, y1) and (x2, y2) and runs max to find the maximum value
                output[row][col] = avg(segment(mtrx, staRow, staCol, endRow, endCol));

                // If the end column goes past the matrix size, move the segment down one segment-n and reset the column
                if (endCol >= mtrx.dimensions().second-1) {
                    staRow += s;
                    endRow += s;
                    staCol = 0;
                    endCol = s-1;
                }
                else{

                    // Move the n-segment to the right
                    staCol += s;
                    endCol += s;
                }

            }
        }

        return output;
    }

}

// Resources
//      https://medium.com/@ramitag18/performing-convolution-on-a-matrix-4682fd364591