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

const int size = 5;
Animal* arr[size];

for (int i = 0; i < size; i++)
{
    if(i < size/2)
        arr[i] = new Dog();
    else
        arr[i] = new Cat();

}

for (int i = 0; i < size; i++) {
    arr[i]->makeSound();
}

for (int i = 0; i < size; i++) {
    delete arr[i];
}

delete i;
delete j;

return 0;
}
