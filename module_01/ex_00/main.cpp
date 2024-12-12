#include "Zombie.hpp"

Zombie* newZombie (std::string name) {
    
    Zombie* z = new Zombie(name);
    return z;
}

void randomChump(std::string name) {
    Zombie z(name);
    z.announce();
}

int main(void) {

    randomChump("Stack");
    Zombie* z = newZombie("Heap");
    
    z->announce();
    z->announce();
    delete z;
    return (0);
}
