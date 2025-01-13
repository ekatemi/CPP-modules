#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
        : ClapTrap("Default_clap_name") , _name("Default") {
        _hitPoints = FragTrap::_hitPoints;
        _energyPoints = ScavTrap::_energyPoints;
        _attackDamage= FragTrap::_attackDamage;
        std::cout << "Default constructor DiamondTrap created " << _name <<  "with Clap Name " << ClapTrap::_name << std::endl;;
}

DiamondTrap::DiamondTrap(std::string name)
        : ClapTrap(name + "_clap_name"), _name(name) {
        _hitPoints = FragTrap::_hitPoints;
        _energyPoints = ScavTrap::_energyPoints;
        _attackDamage= FragTrap::_attackDamage;
        std::cout << "Constructor with param DiamondTrap created bot " << _name <<  " with Clap Name " << ClapTrap::_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src) {
        std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap::~DiamondTrap() {
        std::cout << "Destructor DiamondTrap called\n";
}

// //overload =
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src) {
// Check for self-assignment
        if (this != &src) {
                ClapTrap::operator=(src);
                std::cout << "Assignment operator assigned DiamondTrap from " << src._name << std::endl;
        }
        return *this;
}

void DiamondTrap::whoAmI() {
        std::cout << "I am Diamond Trap " << _name << " with ClapTrap " << ClapTrap::_name << std::endl;
}
