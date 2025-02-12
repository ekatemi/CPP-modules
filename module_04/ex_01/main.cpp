#include "Cat.hpp"
#include "Dog.hpp"


int main()
{


const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;


std::cout << "will output the cat sound!\n";
i->makeSound(); //will output the cat sound!
std::cout << "will output the dog sound!\n";
j->makeSound(); //will output the dog sound!



delete i;
delete j;

return 0;
}
