#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain *_ideas;
    public:
        Dog();
        //Dog(const std::string &type);
        Dog(const Dog &src);
        Dog& operator=(const Dog& src);
        ~Dog();

        void makeSound() const;
        void printFiveIdeas() const;
        void changeIdea(int idx, const std::string& newIdea);
};

#endif
