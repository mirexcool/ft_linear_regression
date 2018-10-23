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

void read_file(char *file_name)
{
    std::ifstream file(file_name);
    std::ofstream file2("output.linpreg");

    std::string             str;
    std::vector<data_csv>   data_vec;
    data_csv                tmp;
    int                     ptr;
    std::string             sub_str = "";
    learning_struct         result;

    int line = 1;
    if (file.fail())
    {
        std::cout << "Error opening file! :(" << std::endl;
        exit(1);
    }
    std::getline(file, str);
    if (str == "km,price"){
        while (std::getline(file, str))
        {
            tmp.km = std::stoi(str, NULL, 10);
            ptr = str.find(',');
            sub_str = str.substr(0, ptr);
//            if (ptr == -1 || sub_str.length() != std::to_string(tmp.km).length())
//                errors(2, line);
            sub_str = str.substr(ptr + 1);
            tmp.price = std::stoi(sub_str, NULL, 10);
//            std::cout << tmp.km << ",";
//            std::cout << tmp.price << std::endl;
            data_vec.push_back(tmp);
            line++;
        }
    }
    else
        errors(1, line);
    file.close();
    result =  GradientDescent(0, 0, 0.0001, 0.0001, data_vec);
    file2 << result.theta0 << std::endl << result.theta1 << std::endl;
    double precision = 0;
    size_t i = 0;
    for (i = 0; i < data_vec.size(); ++i)
    {
        precision+=abs(data_vec[i].price - (result.theta0 + result.theta1*data_vec[i].km));
    }
    precision/=(i+1);
    file2 << precision;
    file2.close();
}

int main(int argc, char **argv) {
    char *file_name = NULL;

    if (argc == 1)
        return (usage());
    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "-f"))
        {
            file_name = argv[i + 1];
        }
    }
    if (file_name)
        read_file(file_name);
    return 0;
}