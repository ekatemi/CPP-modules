#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
IMateriaSource* src = new MateriaSource();

src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
//check type
if (tmp)
    std::cout << "Type is : " << tmp->getType() << std::endl;
else
    std::cout << "Unknown materia\n";

me->equip(tmp);

tmp = src->createMateria("cure"); //null if type incorrect
//check type
if (tmp)
    std::cout << "Type is : " << tmp->getType() << std::endl;
else
    std::cout << "Unknown materia\n";

me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob); //here segfault if type is incorrect
me->use(1, *bob);

delete bob;
delete me;
delete src;

return 0; 
}
