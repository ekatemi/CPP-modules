#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Icharacter.hpp"

class Character : public ICharacter {
        
        protected:
            std::string _name;
            AMateria *inventory[4];
        
        public:
        //default constructor
        Character();
        //param constructor
        Character(const std::string &name);
        //copy constructor
        Character(const Character& src);
        //=assignment operator
        Character& operator=(const Character& src);
        //destructor
        ~Character();
        //methods
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};


#endif
