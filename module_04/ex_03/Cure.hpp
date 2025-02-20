#ifndef CURE_HPP
# define CURE_HPP

#include "Amateria.hpp"
#include "Icharacter.hpp"

class Cure : public AMateria {

    public:
        Cure();
        Cure(const std::string &type);
        Cure(const Cure& src);
        Cure& operator=(const Cure& src);
        virtual ~Cure(); //virtual is optional
        virtual Cure* clone() const; //parent method overload
        void use(ICharacter& target);
};

#endif
