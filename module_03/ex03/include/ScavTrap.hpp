#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    private:
        bool gateMode;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        virtual ~ScavTrap();

        // //overload =
        ScavTrap &operator=(const ScavTrap &src);

        void guardGate();
        bool getMode() const;
        void printStatus();
};



#endif
