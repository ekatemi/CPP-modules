#ifndef ICE_HPP
# define ICE_HPP

#include "Amateria.hpp"
#include "Icharacter.hpp"

class Ice : public AMateria {

    public:
        Ice();
        //Ice(const std::string &type); //no need param constr???
        Ice(const Ice& src);
        Ice& operator=(const Ice& src);
        ~Ice();
        virtual Ice* clone() const; //parent method overload
        void use(ICharacter& target); //TODO implement Icharacter
};

#endif
