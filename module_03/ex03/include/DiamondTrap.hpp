#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &src);
        virtual ~DiamondTrap();

        // //overload =
        DiamondTrap &operator=(const DiamondTrap &src);

        //member function
        void whoAmI();

};



#endif
