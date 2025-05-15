#include "Serializer.hpp"

int main()
{
    Data d(12);
    Data *ptr = &d;
    std::cout << "Ptr is: " << ptr << std::endl;
    uintptr_t raw = Serializer::serialize(ptr);
    Data *recovered = Serializer::deserialize(raw);
    std::cout << "Ptr is: " << recovered << std::endl;
    std::cout << "Recovered d value: " << recovered->getVal() << "\n";
    return 0;
}