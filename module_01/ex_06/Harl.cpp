#include "Harl.hpp"

Harl::Harl( void )
{
}

Harl::~Harl()
{
}

void Harl::debug( void ) {
    std::cout << "Debug level comment\n";
}

void Harl::info( void ) {
    std::cout << "Info level comment\n";
}

void Harl::warning( void ) {
    std::cout << "Warning level comment\n";
}
   void Harl::error( void ) {
    std::cout << "Error level comment\n";
}

void Harl::complain( std::string level ) {
    
    std::string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i <4; i++)
        if (arr[i] == level){
            switch (i)
            {
            case 0:
                std::cout << "[DEBUG]\n";
                debug(); 
            case 1:
                std::cout << "[INFO]\n";
                info();
            case 2:
                std::cout << "[WARNING]\n";
                warning();
            case 3:
                std::cout << "[ERROR]\n";
                error();
                break;
            default:
                std::cout << "default case\n";
                break;
            }       
            return ;    
        }
        std::cout << "[insignificant]\n";
        
}
