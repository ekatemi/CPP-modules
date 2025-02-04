#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const std::string &type);
        WrongCat(const WrongCat &src);
        WrongCat& operator=(const WrongCat& src);
        ~WrongCat();

        void makeSound() const;
};

#endif
