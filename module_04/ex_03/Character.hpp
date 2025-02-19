#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Icharacter.hpp"
#include "Amateria.hpp"

class Character : public ICharacter {
        
        protected:
            std::string _name;
            AMateria *slot[4]; //inventory
            //implement here box for materia
            AMateria** inventory; // Dynamic array
            int size;      // Current number of items
            int capacity;  // Maximum slots
        
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
            std::string const & getName() const;
            void equip(AMateria* m);
            void unequip(int idx);
            void use(int idx, ICharacter& target);

            void resizeInventory();
};


#endif
