#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string m_name;
    public:
    //Constructor
        Zombie();
        Zombie(std::string name);
    //Destructor
        ~Zombie();
        void announce(void);

};

#endif
