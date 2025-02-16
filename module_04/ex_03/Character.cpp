#include "Character.hpp"

//default constructor
Character::Character() : _name("def") {
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

//param constructor
Character::Character(const std::string &name) : _name(name) {
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }    
}

//copy constructor
Character::Character(const Character& src) : _name(src._name) {
    for (int i = 0; i < 4; i++) {
        if (src.inventory[i]) // Check if there is an AMateria in the slot
            inventory[i] = src.inventory[i]->clone(); // Clone creates a new copy
        else
            inventory[i] = NULL;
    }

}

//=assignment operator
Character& Character::operator=(const Character& src) {
    if (this != &src)
    {
        _name = src._name;
        // Free existing memory to prevent memory leaks
        
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }

        // Deep copy the new inventory
        for (int i = 0; i < 4; i++) {
            if (src.inventory[i]) // If the source has an item, clone it
                inventory[i] = src.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }

    }
    return *this;
}

//destructor
Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];  // Free each dynamically allocated AMateria
            inventory[i] = NULL;  // Set to NULL to avoid dangling pointers
        }
    }
}

std::string const & Character::getName() const{
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
}

// void Character::unequip(int idx) {(void)idx; }//TODO

// void Character::use(int idx, ICharacter& target) {}//TODO
