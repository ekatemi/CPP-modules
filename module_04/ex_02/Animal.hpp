#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &src);
    public:
        Animal& operator=(const Animal& src);
        virtual ~Animal();
        virtual void makeSound() const = 0; //pure virtual function
        std::string getType() const;
};

#endif
