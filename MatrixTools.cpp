#include "MatrixTools.hpp"

Matrix segment(Matrix input, std::size_t strRow, std::size_t strCol, std::size_t endRow, std::size_t endCol){

    Matrix output(endRow-strRow+1,endCol-strCol+1);

    std::size_t rowOutput = 0;
    std::size_t colOutput = 0;

    for(std::size_t row = strRow; row <= endRow; row++){
        for(std::size_t col = strCol; col <= endCol; col++){
            output[rowOutput][colOutput] = input[row][col];
            colOutput++;
        }
        colOutput = 0;
        rowOutput++;
    }

    return output;
}

double multSum(Matrix mat1, Matrix mat2){
    std::pair<size_t, size_t> dim_mat1 = mat1.dimensions();
    std::pair<size_t, size_t> dim_mat2 = mat2.dimensions();

    double sum = 0;
    for(std::size_t row = 0; row < dim_mat1.first;row++){
        for(std::size_t col = 0; col < dim_mat1.second;col++){
            sum += mat1[row][col]*mat2[row][col];
        }
    }

    return sum;
}

// Convolution, input 2 matrices, returns feature Matrix
Matrix conv(Matrix mtrx, Matrix kernal){
    // If the input image matrix is of size “n x n” and if the kernel size 
    //  “f x f” and we have defined padding as p then
    //  Then the size of the output image matrix will be n + 2p -f +1

    // n + 2p -f +1
    std::size_t n = sqrt(mtrx.size())- sqrt(kernal.size()) + 1;

    Matrix output(n,n);

    for(std::size_t row = 0; row <= n; row++){
        for(std::size_t col = 0; col <= n; col++){
            
            output[row][col] = 1;
        }
    }


    // Take a segment from input
    // Use multiple then sum function and store result in location


    return output;
}

// Max Pooling, input 2 matrices, returns new Matrix
Matrix maxPool(Matrix mat1, Matrix mat2){
    Matrix m(1,1);
    return m;
}

// Avg Pooling, input 2 matrices, returns new Matrix
Matrix avgPool(Matrix mat1, Matrix mat2){
    Matrix m(1,1);
    return m;
}


//resources
//https://medium.com/@ramitag18/performing-convolution-on-a-matrix-4682fd364591