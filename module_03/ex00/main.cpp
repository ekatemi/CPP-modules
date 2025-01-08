#include "ClapTrap.hpp"

int main(void){
    
    ClapTrap bot("Dan");
    bot.attack("Ben");
    bot.takeDamage(10);
    bot.beRepaired(3);
    
    return 0;
}
