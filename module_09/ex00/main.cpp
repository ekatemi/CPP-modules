#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "wrong args" << std::endl;
        return 1;
    }

    std::string db_name = "data.csv";
    try {
        BitcoinExchange obj(db_name);  // instantiate object with database
        char *in_name = argv[1];
        std::ifstream input(in_name); //input file

        if (!input.is_open())
        {
            std::cerr << "Error: could not open file: " << in_name << std::endl;
            return 1;
        }
        
        std::string line;
        std::getline(input, line);//skip header
        while (std::getline(input, line))
        {
            if (line.empty())
                continue;
            obj.searchDb(line);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // std::string queryDate = "2009-01-05";
    // std::cout << "entry 2009-01-05 =>" << std::fixed << std::setprecision(2) << dataBase[queryDate] << std::endl;
    return 0;
}
