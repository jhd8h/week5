#include "wahoovian.h"
#include <iostream>

//wahoovian function
//add description here
boost::numeric::ublas::matrix<double> wahoovian(boost::numeric::ublas::matrix<double> input) {
    PLOG_INFO << "Entered function wahoovian.";
    
    //store rows and columns in vars with better names
    int rows = input.size1();
    int columns = input.size2();

    //check to see if the matrix meets the function's requirements
    //if this check fails, the matrix will be returned essentially unmodified
    if (rows == columns && rows > 0 && columns > 0) {
        //create a matrix with reversed parameters (rows as columns and vice versa)
        boost::numeric::ublas::matrix<double> modifiedMatrix(columns, rows);

        //loop for each row in the old matrix
        for (int i = 0; i < rows; i++) {
            //loop for each item in that column
            for (int j = 0; j < columns; j++) {
                //add value from old matrix to its transposed position
                //also negate the value
                modifiedMatrix(j,i) = input(i,j) * -1;
            }
        }
    }

    PLOG_WARNING << "Matrix is not square or has no rows or columns";
    //check failed, return the original matrix
    return input;
}