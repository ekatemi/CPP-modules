#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
    _ideas = new Brain(); 
    std::cout << "Default constructor for Cat\n";
}
Cat::Cat(const std::string &type) : Animal("Cat") {
    _ideas = new Brain();
    (void) type;
}

//copy constructor
Cat::Cat(const Cat &src) {
    _ideas = new Brain(*src._ideas);
    _type = src._type;

    std::cout << "Copy constructor for Cat\n";
}

Cat& Cat::operator=(const Cat& src) {
    if (this != &src)
    {
        delete _ideas;
        _ideas = new Brain(*src._ideas);//otherwise it shares Brain ideas
        _type = src._type;
    }
    return *this;
}

Cat::~Cat() {
    delete _ideas;
    std::cout << "Cat destructed\n";
}

void Cat::makeSound() const{
    std::cout << "Mewwww\n";
}



