#include "Ice.hpp"

//default const
Ice::Ice() : AMateria("ice") {
    std::cout << START << "Default constructor Ice called" << END << std::endl;
}

//copy constr
Ice::Ice(const Ice& src) : AMateria(src) {
    std::cout << START << "Copy constructor Ice called" << END << std::endl;
}

//= overload
Ice& Ice::operator=(const Ice& src) {
    std::cout << START << "= operator for Ice called" << END << std::endl;
    if (this != &src)
    {
        AMateria::operator=(src); //we NOT copy type, it is unmutable
    }
    return *this;
}

Ice::~Ice() {
    std::cout << START << "Ice destructed" << END << std::endl;
}

Ice* Ice::clone() const {
    return new Ice(*this);
}

//redefine fun
void Ice::use(ICharacter& target) {
    std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
