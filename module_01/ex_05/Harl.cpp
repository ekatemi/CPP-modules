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
    
    void (Harl::*fcnPtrArr[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i<4; i++)
        if (level == arr[i]){
            (this->*fcnPtrArr[i])(); // Call the function
            return ;
        }
        std::cout << "Wrong level\n";
}
