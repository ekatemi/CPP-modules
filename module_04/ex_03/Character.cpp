#include "Character.hpp"

//default constructor
Character::Character() : _name("def"), countItems(0), inventorySize(4) {
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
    }
    
    inventory = new AMateria*[inventorySize];
    for (int i = 0; i < inventorySize; i++)
    {
       inventory[i] = NULL;
    }
    std::cout << B << "Default constructor Character" << E << std::endl;
}

//param constructor
Character::Character(const std::string &name) : _name(name) , countItems(0), inventorySize(4) {
    std::cout << B << "Param constructor Character" << E << std::endl;
    for (int i = 0; i < 4; i++)
    {
        slot[i] = NULL;
    }
    
    inventory = new AMateria*[inventorySize];
    for (int i = 0; i < inventorySize; i++)
    {
       inventory[i] = NULL;
    }  
}

//copy constructor
Character::Character(const Character& src) :
    _name(src._name), countItems(src.countItems), inventorySize(src.inventorySize) {
    
    std::cout << B << "Copy constructor Character" << E << std::endl;
    for (int i = 0; i < 4; i++) {
        if (src.slot[i]) // Check if there is an AMateria in the slot
            slot[i] = src.slot[i]->clone(); // Clone creates a new copy
        else
            slot[i] = NULL;
    }
    
    // Allocate new memory for inventory and copy the contents
    inventory = new AMateria*[inventorySize]; 
    for (int i = 0; i < countItems; i++) {
        if (src.inventory[i]) // Check if there is an AMateria in the inventory
            inventory[i] = src.inventory[i]->clone(); // Clone creates a new copy
        else
            inventory[i] = NULL;
    }
    // Initialize the rest of the inventory to NULL if countItems < inventorySize
    for (int i = countItems; i < inventorySize; i++) {
        inventory[i] = NULL;
    }
}

//=assignment operator
Character& Character::operator=(const Character& src) {
    if (this != &src)
    {   
        // Free existing memory to prevent memory leaks
        for (int i = 0; i < 4; i++) {
            if (slot[i]) {
                delete slot[i];
                slot[i] = NULL;
            }
        }

        for (int i = 0; i < inventorySize; i++)
        {
            if (inventory[i]) 
            {
                delete inventory[i];
                inventory[i] = NULL;
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
        
        _name = src._name;
        inventorySize = src.inventorySize;
        countItems = src.countItems;
        
        inventory = new AMateria*[inventorySize];
        // Deep copy the new inventory
        for (int i = 0; i < countItems; i++) {
            if (src.inventory[i]) // If the source has an item, clone it
                inventory[i] = src.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << B << "= operator Character" << E << std::endl;
    return *this;
}

//destructor
Character::~Character() {
    std::cout << B << "Character destructed" << E << std::endl;
    for (int i = 0; i < 4; i++) {
        if (slot[i]) {
            delete slot[i];  // Free each dynamically allocated AMateria
            slot[i] = NULL;  // Set to NULL to avoid dangling pointers
        }
    }

    for (int i = 0; i < inventorySize; i++) {
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

void Character::use(int idx, ICharacter& target) {
   if (slot[idx])
    slot[idx]->use(target);
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
    std::cout << "Slots are full, do nothing\n";
    delete m;
}


void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
    {
        std::cout << "Wrong index, it should be from 0 to 3\n";
        return;
    }

    if (!slot[idx])
    {
        std::cout << "Slot[" << idx << "] is empty\n";
        return;
    }
        
        
  
    for (int i = countItems; i < inventorySize; i++)
    {
        if (inventory[i] == NULL) //find first empty space
        {
            inventory[i] = slot[idx];
            slot[idx] = NULL;
            std::cout << "Item moved from slot " << idx << " to Inventory index " << i << std::endl;
            countItems++;
            return;
        }
    }
    resizeInventory();
}

void Character::resizeInventory() {
    inventorySize *= 2;  // Double inventorySize
    AMateria** newInventory = new AMateria*[inventorySize];

    for (int i = 0; i < countItems; i++)
        newInventory[i] = inventory[i];  // Copy existing elements

    delete[] inventory;  // Free old memory
    inventory = newInventory;
    
}
