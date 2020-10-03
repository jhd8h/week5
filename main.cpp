/*
Jacob Dotson
Tools of the Trade - Week 5
2020-10-02
*/

#include <iostream>
#include "wahoovian/wahoovian.h"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <plog/Log.h> // Step1: include the headers
#include "plog/Initializers/RollingFileInitializer.h"

//main function
//modified from example code to meet assignment requirements
//creates two matrices, one 3x3 and one 3x4, and attempts to call
//wahoovian on them. PLOG is used throughout as specified in assignment.
int main(int argc, char* argv[]) {
    using namespace boost::numeric::ublas;

    //init logging
    plog::init(plog::debug, "wahoovian.log");

    PLOG_INFO << "Program Start.";
    PLOG_INFO << "Creating matrices.";

    //create matrices for use in the wahoovian function
    std::cout << "Creating example matrices" << std::endl;
    matrix<double> firstMatrix (3, 3);
    matrix<double> secondMatrix (3, 4);
    for (unsigned i = 0; i < firstMatrix.size1(); ++i) {
        for (unsigned j = 0; j < firstMatrix.size2(); ++j) {
            //fill matrices with data
            firstMatrix(i, j) = 3 * i + j;
            secondMatrix(i, j) = 3 * i + j;
        }
    }

    //initialize remaining values in second matrix
    for (int i = 0; i < 3; i++ ){
        secondMatrix(i,3) = 0;
    }

    PLOG_INFO << "Matrices created, calling wahoovian()";

    //call wahoovian on the first matrix, this should succeed
    std::cout << "First matrix before wahoovian call: " << firstMatrix << std::endl;
    matrix<double> modifiedMatrix = wahoovian(firstMatrix);
    std::cout << "First matrix after wahoovian call: " << modifiedMatrix << std::endl;

    //add a space between calls in the main program for clarity
    std::cout << std::endl;
    
    //call wahoovian on second matrix, this should fail
    std::cout << "Second matrix before wahoovian call: " << secondMatrix << std::endl;
    modifiedMatrix = wahoovian(secondMatrix);
    std::cout << "Second matrix after wahoovian call: " << modifiedMatrix << std::endl;

    PLOG_INFO << "Program ending.";

    //exit program
    return 0;
}
