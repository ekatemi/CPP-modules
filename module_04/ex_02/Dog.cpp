#include "Dog.hpp"


Dog::Dog() : AAnimal("Dog") {
    _ideas = new Brain();
    std::cout << "Default constructor for Dog\n";
}
// Dog::Dog(const std::string &type) : AAnimal("Dog") {
//     (void) type;
//     _ideas = new Brain();
// }

//copy constructor
Dog::Dog(const Dog &src) : AAnimal(src) {
    _ideas = new Brain(*src._ideas);
    std::cout << "Copy constructor for Dog - New Brain at: " << _ideas << ", Copied from: " << src._ideas << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
    if (this != &src)
    {
        AAnimal::operator=(src);
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
void Dog::changeIdea(int idx, const std::string& newIdea) {
    _ideas->setIdea(idx, newIdea);
}
