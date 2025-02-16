#ifndef ICE_HPP
# define ICE_HPP

#include "Amateria.hpp"
#include "Icharacter.hpp"

class Ice : public AMateria {
    private:
        std::string _name;//???
    public:
        Ice();
        //Ice(const std::string &type); //no need param constr???
        Ice(const Ice& src);
        Ice& operator=(const Ice& src);
        ~Ice();
        virtual Ice* clone() const; //parent method overload
        void use(ICharacter&); //TODO implement Icharacter
};

#endif
