#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *_ideas;
    public:
        Dog();
        Dog(const std::string &type);
        Dog(const Dog &src);
        Dog& operator=(const Dog& src);
        ~Dog();

        void makeSound() const;
        void printFiveIdeas() const;
};

#endif
