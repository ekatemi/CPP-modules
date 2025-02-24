#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "Default constructor for WrongCat\n";
}
WrongCat::WrongCat(const std::string &type) : WrongAnimal("WrongCat") {
    (void) type;
}

//copy constructor
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal("WrongCat") {
    _type = src._type;
    std::cout << "Copy constructor for WrongCat\n";
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed\n";
}

void WrongCat::makeSound() const{
    std::cout << "Mewwww\n";
}


