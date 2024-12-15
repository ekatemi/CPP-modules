#include "Harl.hpp"

int main() {
    Harl harl;
    std::string type;
    while (true) {
        std::cout << "Type level of complain: ";
        std::cin >> type;
        if (std::cin.fail()) {
            std::cout << "\nCtrl+D was pressed, exit the program.\n";
            return 0; // Exit the program
        }
        // If input is not empty, break the loop and proceed
        if (!type.empty()) {
            break;
        }
    }
    
    harl.complain(type);
    
    return 0;
}
