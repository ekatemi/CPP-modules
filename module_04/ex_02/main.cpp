#include "Cat.hpp"
#include "Dog.hpp"
#define GREEN "\033[32m"
#define RESET "\033[0m"


int main()
{

//const Animal c; Animal class is abstract
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

std::cout << GREEN << "will output the cat sound" << RESET << std::endl;
i->makeSound(); //will output the cat sound!
std::cout << GREEN << "will output the dog sound!" << RESET << std::endl;
j->makeSound(); //will output the dog sound!

std::cout << "\n";

/* CHECK COPY CONSTRUCTOR (DEEP COPY) */
std::cout << GREEN << "CHECK COPY CONSTRUCTOR (DEEP COPY)" << RESET << std::endl;
Cat myCat;
Cat newCat(myCat); // Copy constructor should be called

std::cout << GREEN << "Before modifying" << RESET << std::endl;
myCat.printFiveIdeas(); //all ideas are "idea"
std::cout << "------------\n";
newCat.printFiveIdeas(); //same output

//change one idea
myCat.changeIdea(0, "hello");

std::cout << GREEN << "After modifying" << RESET << std::endl;
myCat.printFiveIdeas(); //modified ideas
std::cout << "------------\n";
newCat.printFiveIdeas(); //old ideas


/* CHECK ASSIGNMENT OPERATOR */
std::cout << GREEN << "CHECK ASSIGNMENT OPERATOR (DEEP COPY)" << RESET << std::endl;
Cat cat1;
Cat cat3;
cat1.changeIdea(0, "hello");

Cat cat2;
cat2 = cat1; // Assignment operator is called

cat1.printFiveIdeas();
std::cout << "------------\n";
cat2.printFiveIdeas(); // both modified
std::cout << "------------\n";
cat3.printFiveIdeas(); //before modification, not affected by modification

std::cout << "\n";
/* CREATE ARRAY ANIMALS HALF CATS HALF DOGS */
std::cout << GREEN << "CREATE ARRAY ANIMALS HALF CATS HALF DOGS" << RESET << std::endl;
const int size = 6;

Animal* arr[size];
for (int i = 0; i < size; i++)
{
    if(i < size/2)
        arr[i] = new Dog();
    else
        arr[i] = new Cat();

}
//half should be "mewwww", half "gau"
for (int i = 0; i < size; i++) {
    arr[i]->makeSound();
}

//no memory leaks
std::cout << GREEN << "Delete array cats and dogs" << RESET << std::endl;
for (int i = 0; i < size; i++) {
    delete arr[i];
}

delete i;
delete j;

return 0;
}
