#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
class AMateria;



class ICharacter
{
    public:
        virtual ~ICharacter();// need to define only destructor
        virtual std::string const & getName() const = 0; //pure virtual
        virtual void equip(AMateria* m) = 0; //pure virtual
        virtual void unequip(int idx) = 0; //pure virtual
        virtual void use(int idx, ICharacter& target) = 0; //pure virtual
};

#endif
