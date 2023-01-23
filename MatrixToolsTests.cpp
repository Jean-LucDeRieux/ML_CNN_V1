//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Tests the functionality of the matrix tools created to manipulate matrix objects
// Last Modified: 01/23/2023
//      Modified: Added tests for Convolution, Average and Maximum for both pooling

#include "catch.hpp"
#include "MatrixTools.hpp"

TEST_CASE("Multiplication and sum of Matrix","[multSum()]"){

    SECTION("Simple multSum() test"){
        Matrix mat1(2,2);
        
        // [ 1, 2 ]
        // [ 3, 4 ]
        
        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        // 1*1 + 2*2 + 3*3 + 4*4 = 1 + 4 + 9 + 16 = 30
        double result = matrix_tools::multSum(mat1,mat1);

        CHECK(result == 30);
    }

    SECTION("Complex multSum() test"){
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

        // 1*1+2*2+3*3+4*4+5*5+6*6+7*7+8*8+9*9+10*10+
        // 11*11+12*12+13*13+14*14+15*15+16*16+17*17+18*18+19*19+20*20+
        // 21*21+22*22+23*23+24*24+25*25+26*26+27*27+28*28+29*29+30*30+
        // 31*31+32*32+33*33+34*34+35*35+36*36+37*37+38*38+39*39+40*40+
        // 41*41+42*42+43*43+44*44+45*45+46*46+47*47+48*48+49*49+50*50+
        // 51*51+52*52+53*53+54*54+55*55+56*56+57*57+58*58+59*59+60*60+
        // 61*61+62*62+63*63+64*64+65*65+66*66+67*67+68*68+69*69+70*70+
        // 71*71+72*72+73*73+74*74+75*75+76*76+77*77+78*78+79*79+80*80+
        // 81*81+82*82+83*83+84*84+85*85+86*86+87*87+88*88+89*89+90*90+
        // 91*91+92*92+93*93+94*94+95*95+96*96+97*97+98*98+99*99+100*100 = 338350
        
        double result = matrix_tools::multSum(mat1,mat1);

        CHECK(result == 338350);
    }

}

TEST_CASE("Segment","[segment()]"){

    SECTION("Simple segment() test"){
        Matrix mat1(3,3);
        //     0  1  2
        // 0 [ 1, 2, 3]
        // 1 [ 4, 5, 6]
        // 2 [ 7, 8, 9]
        
        mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
        mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;
        mat1[2][0] = 7; mat1[2][1] = 8; mat1[2][2] = 9;

        Matrix result1 = matrix_tools::segment(mat1,0,0,1,1);

        CHECK(result1[0][0] == 1);
        CHECK(result1[0][1] == 2);
        CHECK(result1[1][0] == 4);
        CHECK(result1[1][1] == 5);

        Matrix result2 = matrix_tools::segment(mat1,1,1,2,2);

        CHECK(result2[0][0] == 5);
        CHECK(result2[0][1] == 6);
        CHECK(result2[1][0] == 8);
        CHECK(result2[1][1] == 9);
    }

}

TEST_CASE("Convolution","[conv()]"){

    SECTION("Simple conv() test - input(4,4) and kernal(3,3)"){
        Matrix mat1(4,4);
        Matrix kernal1(3,3);
        
        // [ 1, 2, 3,  4]
        // [ 2, 4, 5,  6]
        // [ 3, 6, 7,  8]
        // [ 4, 8, 9, 10]  Matrix
        
        // [ 0, 1, 0]
        // [ 1, 1, 1]
        // [ 0, 1, 0] Kernal
        
        // [Rows][Cols]
        mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3; mat1[0][3] = 4;
        mat1[1][0] = 2; mat1[1][1] = 4; mat1[1][2] = 5; mat1[1][3] = 6;
        mat1[2][0] = 3; mat1[2][1] = 6; mat1[2][2] = 7; mat1[2][3] = 8;
        mat1[3][0] = 4; mat1[3][1] = 8; mat1[3][2] = 9; mat1[3][3] = 10;

        kernal1[0][0] = 0; kernal1[0][1] = 1; kernal1[0][2] = 0;
        kernal1[1][0] = 1; kernal1[1][1] = 1; kernal1[1][2] = 1;
        kernal1[2][0] = 0; kernal1[2][1] = 1; kernal1[2][2] = 0;
       
        Matrix output = matrix_tools::conv(mat1,kernal1);

        CHECK( output(0,0) == 19);
        CHECK( output(0,1) == 25);
        CHECK( output(1,0) == 28);
        CHECK( output(1,1) == 35);
    }

    
    SECTION("Simple conv() test - input(5,5) and kernal(2,2)"){
        Matrix mat1(5,5);
        Matrix kernal1(2,2);
        
        // [ 1,  2,  3,  4, 5]
        // [ 2, 19,  5, 16, 2]
        // [ 3,  6, 30,  8, 3]
        // [24,  8,  9, 10, 4]
        // [ 5,  4,  3,  2, 5] Matrix
        
        // [ 0, 1, 0]
        // [ 1, 1, 1]
        // [ 0, 1, 0] Kernal
        
        // [Rows][Cols]
        mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3; mat1[0][3] = 4; mat1[0][4] = 5;
        mat1[1][0] = 2; mat1[1][1] = 19; mat1[1][2] = 5; mat1[1][3] = 16; mat1[1][4] = 2;
        mat1[2][0] = 3; mat1[2][1] = 6; mat1[2][2] = 30; mat1[2][3] = 8; mat1[2][4] = 3;
        mat1[3][0] = 24; mat1[3][1] = 8; mat1[3][2] = 9; mat1[3][3] = 10; mat1[3][4] = 4;
        mat1[4][0] = 5; mat1[4][1] = 4; mat1[4][2] = 3; mat1[4][3] = 2; mat1[4][4] = 5;

        kernal1[0][0] = 0; kernal1[0][1] = 1;
        kernal1[1][0] = 1; kernal1[1][1] = 0;
        
        Matrix output = matrix_tools::conv(mat1,kernal1);

        CHECK( output(0,0) == 4);
        CHECK( output(0,1) == 22);
        CHECK( output(0,2) == 9);
        CHECK( output(0,3) == 21);

        CHECK( output(1,0) == 22);
        CHECK( output(1,1) == 11);
        CHECK( output(1,2) == 46);
        CHECK( output(1,3) == 10);

        CHECK( output(2,0) == 30);
        CHECK( output(2,1) == 38);
        CHECK( output(2,2) == 17);
        CHECK( output(2,3) == 13);

        CHECK( output(3,0) == 13);
        CHECK( output(3,1) == 13);
        CHECK( output(3,2) == 13);
        CHECK( output(3,3) == 6);
        
    
    }

    SECTION("Simple conv() test - input(5,5) and kernal(3,3)"){
        Matrix mat1(5,5);
        Matrix kernal1(3,3);
        
        // [ 1,  2,  3,  4, 5]
        // [ 2, 19,  5, 16, 2]
        // [ 3,  6, 30,  8, 3]
        // [24,  8,  9, 10, 4]
        // [ 5,  4,  3,  2, 5] Matrix
        
        // [ 0, 1, 0]
        // [ 1, 1, 1]
        // [ 0, 1, 0] Kernal
        
        // [Rows][Cols]
        mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3; mat1[0][3] = 4; mat1[0][4] = 1;
        mat1[1][0] = 2; mat1[1][1] = 19; mat1[1][2] = 5; mat1[1][3] = 16; mat1[1][4] = 2;
        mat1[2][0] = 3; mat1[2][1] = 6; mat1[2][2] = 30; mat1[2][3] = 8; mat1[2][4] = 3;
        mat1[3][0] = 24; mat1[3][1] = 8; mat1[3][2] = 9; mat1[3][3] = 10; mat1[3][4] = 4;
        mat1[4][0] = 5; mat1[4][1] = 4; mat1[4][2] = 3; mat1[4][3] = 2; mat1[4][4] = 5;

        kernal1[0][0] = 0; kernal1[0][1] = 1; kernal1[0][2] = 0;
        kernal1[1][0] = 1; kernal1[1][1] = 1; kernal1[1][2] = 1;
        kernal1[2][0] = 0; kernal1[2][1] = 1; kernal1[2][2] = 0;
        
        Matrix output = matrix_tools::conv(mat1,kernal1);

        CHECK( output(0,0) == 34);
        CHECK( output(0,1) == 73);
        CHECK( output(0,2) == 35);
        CHECK( output(1,0) == 66);
        CHECK( output(1,1) == 58);
        CHECK( output(1,2) == 67);
        CHECK( output(2,0) == 51);
        CHECK( output(2,1) == 60);
        CHECK( output(2,2) == 33);
        
    
    }


}

TEST_CASE("Average and Max","[avg(), max()]"){

    SECTION("Simple avg() and max() test"){
        Matrix mat1(2,2);

        mat1[0][0] = 1; mat1[0][1] = 2;
        mat1[1][0] = 3; mat1[1][1] = 4;

        CHECK(matrix_tools::avg(mat1) == 2.5);
        CHECK(matrix_tools::max(mat1) == 4);

        mat1[0][0] = 30;

        CHECK(matrix_tools::avg(mat1) == 9.75);
        CHECK(matrix_tools::max(mat1) == 30);
    }
    
}

TEST_CASE("maxPooling","[maxPooling(), max()]"){

    SECTION("Simple avgPool() and maxPool() test"){
        Matrix mat1(4,4);
        Matrix kernal1(3,3);
        
        // [ 1, 2, 3,  4]
        // [ 2, 4, 5,  6]
        // [ 3, 6, 7,  8]
        // [ 4, 8, 9, 10]  Matrix
        
        // [Rows][Cols]
        mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3; mat1[0][3] = 4;
        mat1[1][0] = 2; mat1[1][1] = 4; mat1[1][2] = 5; mat1[1][3] = 6;
        mat1[2][0] = 3; mat1[2][1] = 6; mat1[2][2] = 7; mat1[2][3] = 8;
        mat1[3][0] = 4; mat1[3][1] = 8; mat1[3][2] = 9; mat1[3][3] = 10;

        Matrix avgOutput = matrix_tools::avgPool(mat1);

        // CHECK(avgOutput(0,0) == 2.25);
        // CHECK(avgOutput(0,1) == 4.5);
        // CHECK(avgOutput(1,0) == 5.25);
        // CHECK(avgOutput(1,1) == 8.5);

        Matrix maxOutput = matrix_tools::maxPool(mat1);

        // CHECK(maxOutput(0,0) == 4);
        // CHECK(maxOutput(0,1) == 6);
        // CHECK(maxOutput(1,0) == 8);
        // CHECK(maxOutput(1,1) == 10);
    }
    
}
