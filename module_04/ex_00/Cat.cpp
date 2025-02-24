#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
    std::cout << "Default constructor for Cat\n";
}

//copy constructor
Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "Copy constructor for Cat\n";
}

Cat& Cat::operator=(const Cat& src) {
    if (this != &src)
    {
        Animal::operator=(src);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const{
    std::cout << "Mewwww\n";
}


