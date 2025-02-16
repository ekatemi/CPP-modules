#include "Character.hpp"

//default constructor
Character::Character() : ICharacter(), _name("def") {};
//param constructor
Character::Character(const std::string &name) : ICharacter(), _name(name) {};
//copy constructor
Character::Character(const Character& src) {}; //TODO
//=assignment operator
Character& Character::operator=(const Character& src) {} //TODO

//destructor
Character::~Character() {}; //TODO
std::string const & Character::getName() const{
    return _name;
}
void Character::equip(AMateria* m) {//TODO

}
void Character::unequip(int idx) {};//TODO
void Character::use(int idx, ICharacter& target) {};//TODO