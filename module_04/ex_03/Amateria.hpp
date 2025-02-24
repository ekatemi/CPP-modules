#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Icharacter.hpp"

#define START "\033[32m" //for green text
#define END "\033[0m"


class ICharacter; //forward declaration

//abstract class
class AMateria
{
    protected:
        const std::string _type; //unmutable
    public:
        AMateria(); //we really dont need it
        AMateria(std::string const & type); //param constr
        AMateria(const AMateria &src); //copy constr
        AMateria& operator=(const AMateria& src);//=overload
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0; //pure virtual no need to implement
        virtual void use(ICharacter& target);
};

#endif

//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  -s ./materia
