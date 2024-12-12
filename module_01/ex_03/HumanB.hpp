#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

//weapon could not be at all, so pointer here better
class HumanB
{
private:
   Weapon *weapon;
   std::string name;
public:
    HumanB(std::string _name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon &new_weapon);
};
#endif
