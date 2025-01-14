#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
        _name = "Default";
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage= 30;
        std::cout << "Default constructor FragTrap created bot" << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage= 30;
        std::cout << "Constructor with param FragTrap created bot " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
        std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap() {
        std::cout << "Destructor FragTrap called\n";
}

// //overload =
FragTrap& FragTrap::operator=(const FragTrap &src) {
// Check for self-assignment
        if (this != &src) {
                ClapTrap::operator=(src);
                std::cout << "Assignment operator assigned FragTrap from " << src._name << std::endl;
        }
        return *this;
}

void FragTrap::highFiveGuys() {
        std::cout << "Now FragTrap gives high five\n";
}
