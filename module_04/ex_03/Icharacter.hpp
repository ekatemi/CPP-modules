#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
#include <iostream>

#define B "\033[34m" // Blue text
#define E "\033[0m"    // Reset color

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter();// need to define only destructor
        virtual std::string const & getName() const = 0; //pure virtual
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual void droppedMateriaCount() = 0;
};

#endif
