#include "Ice.hpp"

//param const
Ice::Ice() : AMateria("ice") { }
// //param const
// Ice::Ice(const std::string &type) : AMateria("ice") { }

//copy constr
Ice::Ice(const Ice& src) : AMateria(src) { }

//= overload
Ice& Ice::operator=(const Ice& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}
Ice::~Ice() {}

Ice* Ice::clone() const {
    return new Ice(*this);
}

//redefine fun
void Ice::use(ICharacter& target) {
    std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;

}
