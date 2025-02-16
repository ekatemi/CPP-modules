#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "Amateria.hpp"

class ICharacter
{
    public:
        virtual ~ICharacter();// need to define only destructor
        virtual std::string const & getName() const = 0; //pure virtual
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif
