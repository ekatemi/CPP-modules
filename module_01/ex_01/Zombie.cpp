#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "***Zombie <" << m_name << "> constructed with default constructor\n"; 
}

Zombie::Zombie(std::string name): m_name(name) {
    std::cout << "***Zombie <" << m_name << "> constructed with constructor\n";
}
void Zombie::announce() {
    std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
    std::cout << "***Zombie <" << m_name << "> deleted\n";
}
