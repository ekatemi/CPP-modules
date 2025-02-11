#include "Brain.hpp"

    Brain::Brain() {
        std::cout << "Brain constructed\n";
    }
    Brain::Brain(const Brain &src) : ideas(src.ideas) {
        std::cout << "Copy constructor for Brain class\n";
    }
    Brain& Brain::operator=(const Brain& src) {
        int i = 0;
        while (i < 100)
        {
            ideas[i] = src.ideas[i];
        }
    }
    Brain::~Brain() {
        delete [] ideas;
        std::cout << "Brain destructed\n";
    }