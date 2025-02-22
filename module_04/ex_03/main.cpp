#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    //provided main
    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    //empty storage should be 0
    me->droppedMateriaCount();
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    //check slots are full
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->unequip(0);
    me->unequip(1);
    me->droppedMateriaCount();

    for (int i = 0; i < 4; i++) //free slots
        me->unequip(i);
    me->droppedMateriaCount();

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
      
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    //-------------------------------

    
    
    
    
    delete bob;
    delete me;
    delete src;
    return 0; 
}
