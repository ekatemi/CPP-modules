#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

    std::cout << "Constructor initialized ClapTrap with name " << _name << " and other initial values\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
    std::cout << "Copy constructor copied ClapTrap from " << src._name <<  std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called and deleted ClapTrap " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
    if (this != &src)
    {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage\n";
       // _hitPoints -= _attackDamage;
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
    std::cout << "Attack damage of " << _name << " is " << _attackDamage << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0)
    {
        _hitPoints+= amount;
        _energyPoints--;
        std::cout << "Hit points of " << _name << " after repair is: " << _hitPoints << std::endl;
    }
    else {
        std::cout << "Not enough energy points to repair\n";
    }
}

void ClapTrap::printStatus() {
    std::cout << "\033[32m";
    std::cout << "ClapTrap " << _name << " status:\n";
    std::cout << "Hit points " << _hitPoints << std::endl;
    std::cout << "Energy points " << _energyPoints << std::endl;
    std::cout << "Attack damage " << _attackDamage << std::endl;
    std::cout << "\033[0m";
}
