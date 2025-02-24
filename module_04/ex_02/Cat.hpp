#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain *_ideas;
    public:
        Cat();
        //Cat(const std::string &type);
        Cat(const Cat &src);
        Cat& operator=(const Cat& src);
        ~Cat();

        void makeSound() const;
        void printFiveIdeas() const;
        void changeIdea(int idx, const std::string& newIdea);
};

#endif
