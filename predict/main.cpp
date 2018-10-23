#include "ft_linear_pregression.hpp"

int usage(){
    std::cout << "Usage:";
    std::cout << std::endl;
    return (0);
}

void errors(int num, int line)
{
    if (num == 1)
    {
        std::cout<< "Error: Wrong *.csv format." << std::endl;
        exit(0);
    }
    else if (num == 2)
    {
        std::cout<< "Warning: Wrong line:" << line << std::endl;
    }

}

void read_file(char *file_name, double mileage)
{
    std::ifstream           file(file_name);
    std::string             str;
    learning_struct         result;
    double                  precision = 0;
    if (file.fail())
    {
        std::cout << "Error opening file! :(" << std::endl;
        exit(1);
    }
    std::getline(file, str);
    result.theta0 = std::stod(str);
    std::getline(file, str);
    result.theta1 = std::stod(str);
    std::getline(file, str);
    precision = std::stod(str);
    std::cout << "Estimated price = " << double (result.theta0 + result.theta1 * mileage) << " +- " << precision << std::endl;
    file.close();
}

int main() {
    double mileage = 0;

    std::cout << "Enter the mileage: ";
    std::cin >> mileage;
    read_file((char*)"output.linpreg", mileage);
    return 0;
}