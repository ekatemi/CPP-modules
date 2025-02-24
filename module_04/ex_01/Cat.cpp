#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
    _ideas = new Brain(); 
    std::cout << "Default constructor for Cat\n";
}


//copy constructor
Cat::Cat(const Cat &src) : Animal(src) {
    _ideas = new Brain(*src._ideas);
    //_ideas = src._ideas;  // Shallow copy (BAD! Shares the same memory)
    std::cout << "Copy constructor for Cat - New Brain at: " << _ideas << ", Copied from: " << src._ideas << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    if (this != &src)
    {
        Animal::operator=(src);
        delete _ideas;
        _ideas = new Brain(*src._ideas); //otherwise it shares Brain ideas
    }
    return *this;
}

Cat::~Cat() {
    delete _ideas;
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const {
    std::cout << "Mewwww\n";
}

void Cat::printFiveIdeas() const {
    for(int i = 0; i < 5; i++)
        std::cout << i << " " << _ideas->getIdea(i) << std::endl;
}

void Cat::changeIdea(int idx, const std::string& newIdea) {
    _ideas->setIdea(idx, newIdea);
}



