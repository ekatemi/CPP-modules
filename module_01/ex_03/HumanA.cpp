#include "HumanA.hpp"
//only way to initialize reference is in initialization list
HumanA::HumanA(std::string _name, Weapon& _weapon) : weapon(_weapon), name(_name) {}

HumanA::~HumanA(){}

void HumanA::attack() {
    //no need to check, there is always type of weapon
    std::cout << name << " attacks with their " << weapon.getType() <<std::endl;
}
