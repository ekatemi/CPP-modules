#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name) {}

HumanB::~HumanB() {}

void HumanB::attack() {
    if (!weapon)
        std::cout << name << " has no weapon to attack.\n";
    else
        std::cout << name << " attacks with their " << weapon->getType() <<std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon) {
    weapon = &new_weapon;
}
