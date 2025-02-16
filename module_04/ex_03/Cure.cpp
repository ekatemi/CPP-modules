#include "Cure.hpp"

//param const
Cure::Cure() : AMateria("cure") { }
// //param const
// Ice::Ice(const std::string &type) : AMateria("ice") { }
//copy constr
Cure::Cure(const Cure& src) : AMateria(src) { }

//= overload
Cure& Cure::operator=(const Cure& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}
Cure::~Cure() {}
Cure* Cure::clone() const {
    return new Cure(*this);
}
//redefine fun
void Cure::use(ICharacter& target) {
    std::cout <<  "* heals " << target.getName() << " wounds*" <<std::endl;

}
