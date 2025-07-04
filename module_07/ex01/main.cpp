#include "iter.hpp"

// void arrPrint(char c)
// {
//     std::cout << c;
// }

// void intPrint(int i)
// {
//     std::cout << i;
// }

int main(void)
{
    const char *arr = "Hello";

    int arr_i[5] = {1, 2, 3, 4, 5};

    size_t len = 3;

    ::iter(arr, len, allPrint<char>);
    
    std::cout << std::endl;
    
    ::iter(arr_i, len, allPrint<int>);

    return 0;
}
