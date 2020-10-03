#include <iostream>
#include "wahoovian/wahoovian.h"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <plog/Log.h> // Step1: include the headers
#include "plog/Initializers/RollingFileInitializer.h"

int main(int argc, char* argv[]) {
    using namespace boost::numeric::ublas;

    //init logging
    plog::init(plog::debug, "wahoovian.log");
    PLOG_INFO << "Program beginning.";

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

    PLOG_INFO << "Program ending.";

    return 0;
}
