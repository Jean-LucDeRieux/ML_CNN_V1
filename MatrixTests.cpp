//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Tests to verify Matrix object member functionality
// Last Modified: 01/20/2023
//      Modified: Added header to keep track of file

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Matrix.hpp"
#include "utility"

TEST_CASE("Matrix Creation - 2x2 ","[MATRIX]"){

    SECTION("Verifying the size and dimensions"){
        Matrix mat1(2,2);
        auto dim = mat1.dimensions();
        CHECK(dim.first == 2);
        CHECK(dim.second == 2);
        CHECK(mat1.size() == 4);
    }

    SECTION("Verifying the Array Index Operator []"){
        Matrix mat1(2,2);
        
        // [ 1, 5 ]
        // [ 8, 3 ]
        
        mat1[0][0] = 1; mat1[0][1] = 5;
        mat1[1][0] = 8; mat1[1][1] = 3;

        CHECK(mat1[0][0] == 1);
        CHECK(mat1[0][1] == 5);
        CHECK(mat1[1][0] == 8);
        CHECK(mat1[1][1] == 3);
    }

    SECTION("Verifying the Assignment Operator ()"){
        Matrix mat1(2,2);

        // [ 1, 2 ]
        // [ 3, 4 ]
        
        mat1(0,0) = 1; mat1(0,1) = 2;
        mat1(1,0) = 3; mat1(1,1) = 4;

        CHECK(mat1(0,0) == 1);
        CHECK(mat1(0,1) == 2);
        CHECK(mat1(1,0) == 3);
        CHECK(mat1(1,1) == 4);
    }
}

TEST_CASE("Matrix Creation - 10x10","[MATRIX]"){

    SECTION("Verifying the size and dimensions"){
        Matrix mat1(10,10);
        auto dim = mat1.dimensions();
        CHECK(dim.first == 10);
        CHECK(dim.second == 10);
        CHECK(mat1.size() == 100);
    }

    SECTION("Verifying the Array Index Operator []"){
        Matrix mat1(10,10);
        
        // [  1,    2,   3,   4,   5,   6,   7,   8,   9, 10]
        // [ 11,   12,  13,  14,  15,  16,  17,  18,  19, 20]
        // [ 21,   22,  23,  24,  25,  26,  27,  28,  29, 30]
        // [ 31,   32,  33,  34,  35,  36,  37,  38,  39, 40]
        // [ 41,   42,  43,  44,  45,  46,  47,  48,  49, 50]
        // [ 51,   52,  53,  54,  55,  56,  57,  58,  59, 60]
        // [ 61,   62,  63,  64,  65,  66,  67,  68,  69, 70]
        // [ 71,   72,  73,  74,  75,  76,  77,  78,  79, 80]
        // [ 81,   82,  83,  84,  85,  86,  87,  88,  89, 90]
        // [ 91,   92,  93,  94,  95,  96,  97,  98,  99, 100]
       
        std::size_t row = 0;
        for(std::size_t i = 0; i <= 9; i++){
            
            for(std::size_t col = 0; col <= 9; col++){
                mat1[row][col] = (i*10)+(col+1);
            }
            row++;
        }

        row = 0;
        for(std::size_t i = 0; i <= 9; i++){

            for(std::size_t col = 0; col <= 9; col++){
                CHECK(mat1[row][col] == (i*10)+(col+1));
            }
            row++;
        }

    }

    SECTION("Verifying the Assignment Operator ()"){
        Matrix mat1(10,10);
        
        // [  1,    2,   3,   4,   5,   6,   7,   8,   9, 10]
        // [ 11,   12,  13,  14,  15,  16,  17,  18,  19, 20]
        // [ 21,   22,  23,  24,  25,  26,  27,  28,  29, 30]
        // [ 31,   32,  33,  34,  35,  36,  37,  38,  39, 40]
        // [ 41,   42,  43,  44,  45,  46,  47,  48,  49, 50]
        // [ 51,   52,  53,  54,  55,  56,  57,  58,  59, 60]
        // [ 61,   62,  63,  64,  65,  66,  67,  68,  69, 70]
        // [ 71,   72,  73,  74,  75,  76,  77,  78,  79, 80]
        // [ 81,   82,  83,  84,  85,  86,  87,  88,  89, 90]
        // [ 91,   92,  93,  94,  95,  96,  97,  98,  99, 100]
       
        std::size_t row = 0;
        for(std::size_t i = 0; i <= 9; i++){
            
            for(std::size_t col = 0; col <= 9; col++){
                mat1(row,col) = (i*10)+(col+1);
            }
            row++;
        }

        row = 0;
        for(std::size_t i = 0; i <= 9; i++){
            
            for(std::size_t col = 0; col <= 9; col++){
                CHECK(mat1(row,col) == (i*10)+(col+1));
            }
            row++;
        }

    }
}
