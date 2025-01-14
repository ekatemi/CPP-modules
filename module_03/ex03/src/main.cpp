#include "DiamondTrap.hpp"

int main() {
    
    DiamondTrap dt;
    dt.whoAmI();
    
    std::cout << std::endl;
    std::cout << "CONSTRUCTOR WITH ARG -------------------->\n";
    std::cout << std::endl;

    DiamondTrap dr("John");
    dr.whoAmI();

    return 0;
}
