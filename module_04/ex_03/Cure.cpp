#include "Cure.hpp"

//default const
Cure::Cure() : AMateria("cure") {
    std::cout << START << "Default constructor Cure called" << END << std::endl;
}



//copy constr
Cure::Cure(const Cure& src) : AMateria(src) {
    std::cout << START << "Copy constructor Cure called" << END << std::endl;
}

//= overload
Cure& Cure::operator=(const Cure& src) {
    std::cout << START << "= operator Cure called" << END << std::endl;
    if (this != &src)
    {
       AMateria::operator=(src);
    }
    return *this;
}

Cure::~Cure() {
    std::cout << START << "Cure destructed" << END << std::endl;
}

Cure* Cure::clone() const {
    return new Cure(*this);
}

//redefine fun
void Cure::use(ICharacter& target) {
    std::cout <<  "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
