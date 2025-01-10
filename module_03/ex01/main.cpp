#include "ClapTrap.hpp"

int main(void){
    
    ClapTrap bot("Dan");
    bot.printStatus();
    bot.attack("Ben");
    bot.printStatus();
    bot.takeDamage(10);
    bot.attack("Ben");
    bot.printStatus();
    for (int i = 0; i < 15; i++)
        bot.beRepaired(3);
    bot.printStatus();
    
    return 0;
}
