/*
Jacob Dotson
Tools of the Trade - Week 5 
2020-09-30
*/

#ifndef WAHOOVIAN_H
#define WAHOOVIAN_H

//include the boost libraries that the wahoovian function will use
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

//include plog stuff so that we can log with it
#include <plog/Log.h>
#include "../plog/Initializers/RollingFileInitializer.h"

boost::numeric::ublas::matrix<double> wahoovian(boost::numeric::ublas::matrix<double> input);

#endif