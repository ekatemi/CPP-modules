#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap {
    private:

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap();

        //overload =
        ScavTrap &operator=(const ScavTrap &src) {
            if (this != &src)
            {
                //???;;
            }
            return *this;
        }
}

#endif