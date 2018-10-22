//
// Created by Mirex on 22.10.2018.
//

#ifndef FT_LINEAR_PREGRESSION_FT_LINEAR_PREGRESSION_HPP
#define FT_LINEAR_PREGRESSION_FT_LINEAR_PREGRESSION_HPP


#include <iostream>
#include "string.h"
#include <fstream>
#include "vector"
#include <cmath>

struct data_csv
{
    double km;
    double price;
};

struct learning_struct
{
    double theta0;
    double  theta1;
};

learning_struct GradientDescent (double theta0, double theta1, double LearningRate1, double LearningRate2,std::vector<data_csv> data );


#endif //FT_LINEAR_PREGRESSION_FT_LINEAR_PREGRESSION_HPP
