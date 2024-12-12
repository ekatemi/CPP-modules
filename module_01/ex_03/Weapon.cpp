#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(std::string _type) : type(_type){}

Weapon::~Weapon(){}
//returns reference to weapon type 
const std::string& Weapon::getType() {
    return type;
}
void Weapon::setType(std::string weapon) {
    type = weapon;
}
