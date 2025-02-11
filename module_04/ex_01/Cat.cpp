#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
    std::cout << "Default constructor for Cat\n";
}
Cat::Cat(const std::string &type) : Animal("Cat") {
    (void) type;
}

//copy constructor
Cat::Cat(const Cat &src) {
    _type = src._type;
    std::cout << "Copy constructor for Cat\n";
}

Cat& Cat::operator=(const Cat& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const{
    std::cout << "Mewwww\n";
}


