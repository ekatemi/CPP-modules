#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

//reference here, because Human A always has a weapon. Reference can not point to NULL
class HumanA
{
private:
   Weapon& weapon;
   std::string name;
public:
    HumanA(std::string _name, Weapon& _weapon); //it is always constructed with ref to Weapon
    ~HumanA();
    void attack();
};
#endif
