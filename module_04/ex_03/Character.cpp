#include "Character.hpp"

//default constructor
Character::Character() : _name("def"), size(0), capacity(4) {
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
    }
    
    inventory = new AMateria*[capacity];
    for (int i = 0; i < capacity; i++)
    {
       inventory[i] = NULL;
    }
}

//param constructor
Character::Character(const std::string &name) : _name(name) , size(0), capacity(4) {
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
    }
    
    inventory = new AMateria*[capacity];
    for (int i = 0; i < capacity; i++)
    {
       inventory[i] = NULL;
    }  
}

//copy constructor
Character::Character(const Character& src) :
    _name(src._name), size(src.size), capacity(src.capacity) {
    
    for (int i = 0; i < 4; i++) {
        if (src.slot[i]) // Check if there is an AMateria in the slot
            slot[i] = src.slot[i]->clone(); // Clone creates a new copy
        else
            slot[i] = NULL;
    }
    
    // Allocate new memory for inventory and copy the contents
    inventory = new AMateria*[capacity]; 
    for (int i = 0; i < size; i++) {
        if (src.inventory[i]) // Check if there is an AMateria in the inventory
            inventory[i] = src.inventory[i]->clone(); // Clone creates a new copy
        else
            inventory[i] = NULL;
    }
    // Initialize the rest of the inventory to NULL if size < capacity
    for (int i = size; i < capacity; i++) {
        inventory[i] = NULL;
    }

}

//=assignment operator
Character& Character::operator=(const Character& src) {
    if (this != &src)
    {
        _name = src._name;
        capacity = src.capacity;
        size = src.size;
        
        // Free existing memory to prevent memory leaks
        for (int i = 0; i < 4; i++) {
            if (slot[i]) {
                delete slot[i];
                slot[i] = NULL;
            }
        }

        // Deep copy the new slot
        for (int i = 0; i < 4; i++) {
            if (src.slot[i]) // If the source has an item, clone it
                slot[i] = src.slot[i]->clone();
            else
                slot[i] = NULL;
        }
        delete[] inventory;
        inventory = new AMateria*[capacity];
        
        // Deep copy the new inventory
        for (int i = 0; i < size; i++) {
            if (src.inventory[i]) // If the source has an item, clone it
                inventory[i] = src.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        
        // Initialize the rest of the inventory to NULL if size < capacity
        for (int i = size; i < capacity; i++) {
            inventory[i] = NULL;
        }
    }
    return *this;
}

//destructor
Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (slot[i]) {
            delete slot[i];  // Free each dynamically allocated AMateria
            slot[i] = NULL;  // Set to NULL to avoid dangling pointers
        }
    }

    for (int i = 0; i < capacity; i++) {
        if (inventory[i]) {
            delete inventory[i];  // Free each dynamically allocated AMateria
            inventory[i] = NULL;  // Set to NULL to avoid dangling pointers
        }
    }
    delete[] inventory;
}

std::string const & Character::getName() const{
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] == NULL)
        {
            slot[i] = m;
            return ;
        }
    }
}


void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
    {
        std::cout << "Wrong index, it should be from 0 to 3\n";
        return;
    }

    if (!slot[idx])
        return;
        
  
    for (int i = 0; i < capacity; i++)
    {
        if (inventory[i] == NULL) //find first empty space
        {
            inventory[i] = slot[idx];
            slot[idx] = NULL;
            return;
        }
    }
    resizeInventory();
}

void Character::use(int idx, ICharacter& target) {
   slot[idx]->use(target);//????? TO CHECK
}

void Character::resizeInventory() {
    capacity *= 2;  // Double capacity
    AMateria** newInventory = new AMateria*[capacity];

    for (int i = 0; i < size; i++)
        newInventory[i] = inventory[i];  // Copy existing elements

    delete[] inventory;  // Free old memory
    inventory = newInventory;
}
