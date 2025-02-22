#ifndef ICE_HPP
# define ICE_HPP

#include "Amateria.hpp"
#include "Icharacter.hpp"

class Ice : public AMateria {

    public:
        Ice();
        
        Ice(const Ice& src);
        Ice& operator=(const Ice& src);
        virtual ~Ice(); //virtual is optional
        virtual Ice* clone() const; //parent method overload
        void use(ICharacter& target);
};

#endif
