#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat("gg");
const WrongAnimal* x = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << x->getType() << " " << std::endl;

std::cout << "will output the cat sound!\n";
i->makeSound(); //will output the cat sound!
std::cout << "will output the dog sound!\n";
j->makeSound(); //will output the dog sound!
meta->makeSound();

std::cout << "will output the wrong cat sound!\n";
x->makeSound();

delete meta;
delete j;
delete i;
delete x;

return 0;
}
