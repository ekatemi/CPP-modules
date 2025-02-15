#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(const Brain &src);
        Brain& operator=(const Brain& src);
        virtual ~Brain();

        std::string getIdea( int idx ) const;
        void setIdea(int idx, const std::string& idea);
};

// std::ostream& operator<<(std::ostream& os, const Brain& obj);
#endif
