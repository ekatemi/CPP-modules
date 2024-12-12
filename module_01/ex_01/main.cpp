#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name);

int main(void) {

    Zombie *horde = zombieHorde(3, "DAN");

    int i = 0;
    while(i < 3) {
        std::cout << "Zombie #" << i << " announce:\n";
        horde[i++].announce();
    }
    delete[] horde;
    horde[7].announce();//why?
    return (0);
}
