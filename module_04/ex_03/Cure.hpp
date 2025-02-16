#ifndef CURE_HPP
# define CURE_HPP

#include "Amateria.hpp"
#include "Icharacter.hpp"

class Cure : public AMateria {

    public:
        Cure();
        //Ice(const std::string &type); //no need param constr???
        Cure(const Cure& src);
        Cure& operator=(const Cure& src);
        ~Cure();
        virtual Cure* clone() const; //parent method overload
        void use(ICharacter&); //TODO implement Icharacter
};

#endif
