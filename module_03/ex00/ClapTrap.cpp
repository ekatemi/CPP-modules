#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

    std::cout << "Constructor initialized ClapTrap with name " << _name << " and other initial values\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "Copy constructor copied ClapTrap " << other._name <<  " and other values\n";
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called and deleted ClapTrap " << _name << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage\n";
        _hitPoints -= _attackDamage;
        _energyPoints--;
    }
    else if (_hitPoints == 0) {
        std::cout << "No hit points left for attack\n";
    }
    else if (_energyPoints == 0) {
        std::cout << "No energy left for attack\n";
    }
}
void ClapTrap::takeDamage(unsigned int amount) {
    _attackDamage += amount;
    std::cout << "Damage is now " << _attackDamage << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0)
    {
        _hitPoints-= amount;
        _energyPoints--;
        std::cout << "Not enough energy points to repair\n";
    }
    else {
        std::cout << "Not enough energy points to repair\n";
    }
    
}
