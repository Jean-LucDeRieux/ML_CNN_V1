cmake_minimum_required(VERSION 3.5...3.22)
project(CNN CXX)
#-------------------------

add_executable(matrixTesting
	catch.hpp 
	MatrixTests.cpp
	Matrix.cpp 
	Matrix.hpp
	MatrixToolsTests.cpp 
	MatrixTools.cpp 
	MatrixTools.hpp)

enable_testing()

add_test(Test1
	MatrixTests.cpp)
#-------------------------
