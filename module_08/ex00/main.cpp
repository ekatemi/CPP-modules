#include "easyfind.hpp"

int main()
{
    std::vector<int> vec = {1, 2, 6, 8, 3};
    try
    {
        int i = ::easyfind(vec, 3);
        std::cout << "Index of n is " << i << std::endl;
        i = ::easyfind(vec, 30);
        std::cout << "Index of n is " << i << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}