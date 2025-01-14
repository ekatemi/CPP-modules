#include "ScavTrap.hpp"

int main(void) {
    ScavTrap bot;
    ScavTrap bot1("Ann");
    bot.printStatus();
    bot1.printStatus();
    ScavTrap bot3(bot1);
    bot3.printStatus();
    ScavTrap bot4 = bot3;
    std::cout << bot4.getMode() << std::endl;
    bot4.guardGate();
    for (int i = 0; i < 15; i++)
        bot4.attack("Lenny");
    for (int i = 0; i < 15; i++)
        bot4.beRepaired(3);
    bot4.printStatus();

    return 0;
}
