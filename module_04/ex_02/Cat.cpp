#include "Cat.hpp"


Cat::Cat() : AAnimal("Cat") {
    _ideas = new Brain(); 
    std::cout << "Default constructor for Cat\n";
}

//copy constructor
Cat::Cat(const Cat &src) : AAnimal(src) {
    _ideas = new Brain(*src._ideas);
    std::cout << "Copy constructor for Cat - New Brain at: " << _ideas << ", Copied from: " << src._ideas << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    if (this != &src)
    {
        AAnimal::operator=(src);
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



