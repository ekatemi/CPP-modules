#include <vector> // ✅ Needed for std::vector
#include <iostream>

int main()
{
    std::vector<int> v(1); // ✅ OK: vector with one element initialized to 0
    std::cout << v[0] << '\n';
    return 0;
}