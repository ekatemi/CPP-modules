#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default") {
    std::cout << "Default constructor for AAnimal class\n";
}
AAnimal::AAnimal(const std::string &type) : _type(type) {
    std::cout << "Param constructor for AAnimal class\n";
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
    std::cout << "Copy constructor for AAnimal class\n";
}
AAnimal& AAnimal::operator=(const AAnimal& src) {
    if (this != &src) {
        _type = src._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructed\n";
}



std::string AAnimal::getType() const {
    return _type;
}
