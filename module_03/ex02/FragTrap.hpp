#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        virtual ~FragTrap();

        // //overload =
        FragTrap &operator=(const FragTrap &src);

        void highFiveGuys( void );
};



#endif
