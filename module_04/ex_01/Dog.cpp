#include "Dog.hpp"


Dog::Dog() : Animal("Dog") {
    std::cout << "Default constructor for Cat\n";
}
Dog::Dog(const std::string &type) : Animal("Cat") {
    (void) type;
}

//copy constructor
Dog::Dog(const Dog &src) {
    _type = src._type;
    std::cout << "Copy constructor for Dog\n";
}

Dog& Dog::operator=(const Dog& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructed\n";
}

void Dog::makeSound() const{
    std::cout << "Gau\n";
}


