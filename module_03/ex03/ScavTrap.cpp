#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
        _name = "Default";
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage= 20;
        gateMode = false;
        std::cout << "Default constructor ScavTrap created bot " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage= 20;
        gateMode = false;
        std::cout << "Constructor with param ScavTrap created bot " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
        gateMode = src.gateMode;
        std::cout << "ScavTrap copy constructor called\n";
}

        ScavTrap::~ScavTrap() {
        std::cout << "Destructor Scav Trap called\n";
}

// //overload =
ScavTrap& ScavTrap::operator=(const ScavTrap &src) {
// Check for self-assignment
        if (this != &src) {
                ClapTrap::operator=(src);
                gateMode = src.gateMode;
                std::cout << "Assignment operator assigned ScavTrap from " << src._name << std::endl;
        }
        return *this;
}

void ScavTrap::guardGate() {
        gateMode = true;
        std::cout << "Now ScavTrap " << _name << " is in Gate keeper mode\n";
}

bool ScavTrap::getMode() const {
        return gateMode;
}

void ScavTrap::printStatus() {
        ClapTrap::printStatus();
        std::cout << "\033[32m";
        std::cout << "Gate mode of " << _name << " is " << gateMode << std::endl; 
        std::cout << "\033[0m";
}

