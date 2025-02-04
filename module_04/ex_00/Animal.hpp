#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &src);
        Animal& operator=(const Animal& src);
        virtual ~Animal();

    
        void makeSound();
};

#endif
