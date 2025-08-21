#include "PmergeMe.hpp"
#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./PmergeMe \"num1 num2 num3 ...\"" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    char* token = std::strtok(argv[1], " ");  // split by space
    while (token) {
        char* end;
        long num = std::strtol(token, &end, 10);

        if (*end != '\0' || num <= 0) {
            std::cerr << "Error: invalid number '" << token << "'" << std::endl;
            return 1;
        }

        numbers.push_back(static_cast<int>(num));
        token = std::strtok(NULL, " ");
    }

    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << std::endl;
}