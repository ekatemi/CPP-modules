#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal& operator=(const WrongAnimal& src);
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};

#endif
