#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
    protected:
        std::string _type;
        AAnimal();
        AAnimal(const std::string &type);
        AAnimal(const AAnimal &src);
    public:
        AAnimal& operator=(const AAnimal& src);
        virtual ~AAnimal();
        virtual void makeSound() const = 0; //pure virtual function
        std::string getType() const;
};

#endif
