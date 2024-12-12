#include "Zombie.hpp"

Zombie::Zombie(std::string name): m_name(name) {
    std::cout << "Zombie " << m_name << " is created\n";
}

Zombie::~Zombie() {
    std::cout << "Zombie " << m_name << " is deleted\n";
}
void Zombie::announce() {
    std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}
