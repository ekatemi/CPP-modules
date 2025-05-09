#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *_ideas;
    public:
        Cat();
       
        Cat(const Cat &src);
        Cat& operator=(const Cat& src);
        ~Cat();

        void makeSound() const;
        void printFiveIdeas() const;
        void changeIdea(int idx, const std::string& newIdea);
};

#endif
