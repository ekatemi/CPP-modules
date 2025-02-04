#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
    std::cout << "Default constructor for WrongAnimal class\n";
}
WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
    std::cout << "Param constructor for WrongAnimal class\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
    std::cout << "Copy constructor for WrongAnimal class\n";
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
    if (this != &src) {
        _type = src._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor for Wrong Animal class\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "wrong sound\n";
}

std::string WrongAnimal::getType() const {
    return _type;
}
