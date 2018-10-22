#include "ft_linear_pregression.hpp"

double estimatePrice(double theta0, double theta1, double millage)
{
    return (theta0 + (theta1 * millage));
}

double  SumTheta0(double theta0, double theta1, std::vector<data_csv> data, double scale )
{
    double sum = 0;

    for (size_t i = 0; i <data.size() ; ++i) {
        sum+= estimatePrice(theta0, theta1, data[i].km + scale) - data[i].price;
    }
    return sum;
}

double  SumTheta1(double theta0, double theta1, std::vector<data_csv> data, double scale )
{
    double sum = 0;

    for (size_t i = 0; i <data.size() ; ++i) {
        sum+= (estimatePrice(theta0, theta1, data[i].km + scale ) - data[i].price) * data[i].km;
    }
    return sum;
}

learning_struct GradientDescent (double theta0, double theta1, double LearningRate1, double LearningRate2,std::vector<data_csv> data )
{
    double sum0;
    double sum1;
    double tmp_theta0 = 1;
    double tmp_theta1 = 1;
    learning_struct  ret;
    double max = 0;
    double min = 999999;


    for (size_t i = 0; i <data.size() ; ++i) {
        if (data[i].km > max)
            max = data[i].km;
        if (data[i].km < min)
            min = data[i].km;
    }

    double scale = max - min;
    double scaled_min = min / scale;

    for (size_t i = 0; i <data.size() ; ++i) {
        data[i].km = (data[i].km - min) / scale;
    }

    while (true)
    {
        sum0 = SumTheta0(theta0, theta1, data, scaled_min);
        sum1 = SumTheta1(theta0, theta1, data, scaled_min);
        tmp_theta0 = LearningRate1 * sum0 / data.size();
        tmp_theta1 = LearningRate2 * sum1 / data.size();

        if (std::fabs(tmp_theta0) < 0.00001 && fabs(tmp_theta1) < 0.00001)
        {
            ret.theta0 = theta0;
            ret.theta1 = theta1 / scale;
            return ret;
        }

        theta0-= tmp_theta0;
        theta1-= tmp_theta1;
    }
}