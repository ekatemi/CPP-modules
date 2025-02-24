#include "Dog.hpp"


Dog::Dog() : Animal("Dog") {
    _ideas = new Brain();
    std::cout << "Default constructor for Dog\n";
}


//copy constructor
Dog::Dog(const Dog &src) : Animal(src) {
    _ideas = new Brain(*src._ideas);
    std::cout << "Copy constructor for Dog\n";
}

Dog& Dog::operator=(const Dog& src) {
    if (this != &src)
    {
        Animal::operator=(src);
        delete _ideas;
        _ideas = new Brain(*src._ideas);
    }
    return *this;
}

Dog::~Dog() {
    delete _ideas;
    std::cout << "Dog destructed\n";
}

void Dog::makeSound() const{
    std::cout << "Gau\n";
}

void Dog::printFiveIdeas() const {
    for(int i = 0; i < 5; i++)
        std::cout << i << " " << _ideas->getIdea(i) << std::endl;
}


