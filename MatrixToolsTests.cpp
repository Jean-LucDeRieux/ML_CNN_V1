//   Author Name: Jean-Luc DeRieux
//  Date Created: 01/14/2023
//         About: Tests the functionality of the matrix tools created to manipulate matrix objects
// Last Modified: 01/20/2023
//      Modified: Added header to keep track of file

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

TEST_CASE("segment","[segment()]"){

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

    SECTION("Simple conv() test"){
      
    }

    SECTION("Complex conv() test"){
 
    }

}

