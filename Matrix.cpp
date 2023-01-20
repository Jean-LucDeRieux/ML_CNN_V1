#include "Matrix.hpp"

// Constructor for a matrix with rows and cols
Matrix::Matrix(std::size_t rows, std::size_t cols){
    
    // Setting the rows and columns
    this->m = rows;
    this->n = cols;

    // Sets number of rows for the matrix
    this->matrix.resize(rows);

    // Sets the number of columns per row
    for (auto &row : this->matrix) {
        row.resize(cols);
    }
}

// Array Index Operator []
std::vector<double>& Matrix::operator[](std::size_t row)
{
    return this->matrix[row];
}
const std::vector<double>& Matrix::operator[](std::size_t row) const
{
    return this->matrix[row];
}

// Assignment Operator ()
double& Matrix::operator()(std::size_t row, std::size_t col){
    return this->matrix[row][col];
}
const double& Matrix::operator()(std::size_t row, std::size_t col) const{
    return this->matrix[row][col];
}

//Retrieves the dimensions of the matrix
std::pair<std::size_t, std::size_t> Matrix::dimensions(){

    return std::make_pair(this->m, this->n);
}

//Retrieves the dimensions of the matrix
std::size_t Matrix::size(){
    return (this->m*this->n);
}


