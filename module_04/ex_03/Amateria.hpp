#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Icharacter.hpp"

//abstract class
class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type); //param constr
        AMateria(const AMateria &src); //copy constr
        AMateria& operator=(const AMateria& src);//=overload
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0; //no need to implement
        virtual void use(ICharacter& target);
};

#endif
