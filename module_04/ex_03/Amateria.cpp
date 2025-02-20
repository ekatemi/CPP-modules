#include "Amateria.hpp"

AMateria::AMateria() : _type("default") {
    std::cout << START << "Default constructor Amateria called" << END << std::endl;
}
AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << START << "Param constructor Amateria called" << END << std::endl;
}

AMateria::AMateria(const AMateria &src) : _type(src._type) {
    std::cout << START << "Copy constructor Amateria called" << END << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    std::cout << START << "Assignment operator Amateria called" << END << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << START << "Amateria destructed" << END << std::endl;
}

std::string const& AMateria::getType() const {
    return _type;
}

//should be redefined in derived classes
void AMateria::use(ICharacter& target) {
    std::cout << "* Abstract use on " << target.getName() << " *" << std::endl;
}
