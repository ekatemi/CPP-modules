#include "FragTrap.hpp"

int main() {
    std::cout << "Testing ClapTrap class...\n";

    // Default constructor
    ClapTrap clap1;
    clap1.printStatus();
    clap1.attack("Enemy A");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    clap1.printStatus();

    std::cout << "\nParameterized constructor for ClapTrap...\n";
    ClapTrap clap2("Clappy");
    clap2.printStatus();

    std::cout << "\nCopy constructor for ClapTrap...\n";
    ClapTrap clap3(clap2);
    clap3.printStatus();

    std::cout << "\nAssignment operator for ClapTrap...\n";
    clap1 = clap2;
    clap1.printStatus();

    std::cout << "\nTesting FragTrap class...\n";

    // Default constructor for FragTrap
    FragTrap frag1;
    frag1.printStatus();
    frag1.attack("Enemy B");
    frag1.takeDamage(20);
    frag1.beRepaired(10);
    frag1.highFiveGuys();
    frag1.printStatus();

    std::cout << "\nParameterized constructor for FragTrap...\n";
    FragTrap frag2("Fraggy");
    frag2.printStatus();

    std::cout << "\nCopy constructor for FragTrap...\n";
    FragTrap frag3(frag2);
    frag3.printStatus();

    std::cout << "\nAssignment operator for FragTrap...\n";
    frag1 = frag2;
    frag1.printStatus();

    std::cout << "\nEnd of tests. Destructors will now be called as objects go out of scope.\n";

    return 0;
}
