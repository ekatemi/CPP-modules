#include "Amateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &src) : _type(src._type) {}
AMateria& AMateria::operator=(const AMateria& src) {
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
    return _type;
}
//should be redefined in derived classes
void AMateria::use(ICharacter& target) {
    std::cout << "* abstract use " << target.getName() << " *" << std::endl;
}
