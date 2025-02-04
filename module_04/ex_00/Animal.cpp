#include "Animal.hpp"

Animal::Animal() : _type("default") {
    std::cout << "Default constructor for Animal class\n";
}
Animal::Animal(const std::string &type) : _type(type) {
    std::cout << "Param constructor for Animal class\n";
}

Animal::Animal(const Animal &src) : _type(src._type) {
    std::cout << "Copy constructor for Animal class\n";
}
Animal& Animal::operator=(const Animal& src) {
    if (this != &src) {
        _type = src._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor for Animal class\n";
}

void Animal::makeSound() const {
    std::cout << "none sound\n";
}

std::string Animal::getType() const {
    return _type;
}
