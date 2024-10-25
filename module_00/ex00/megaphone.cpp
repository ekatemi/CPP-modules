#include <iostream>
#include <string>

void capitalize(std::string &str)
{
    size_t i = 0;
    while (i < str.length())
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
}

int main(int argc, char** argv) 
{
    if (argc < 2) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } 
    else 
    {
        for (int i = 1; i < argc; i++)
        {
            std::string argument = argv[i];
            capitalize(argument);
            std::cout << argument;
            if (i < argc - 1)
            {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
    return 0;
}