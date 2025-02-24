#include "Dog.hpp"


Dog::Dog() : Animal("Dog") {
    std::cout << "Default constructor for Dog\n";
}

//copy constructor
Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "Copy constructor for Dog\n";
}

Dog& Dog::operator=(const Dog& src) {
    if (this != &src)
    {
        Animal::operator=(src);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructed\n";
}

void Dog::makeSound() const{
    std::cout << "Gau\n";
}


