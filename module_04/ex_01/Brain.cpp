#include "Brain.hpp"

    Brain::Brain() {
        int i = 0;
        while (i < 100)
        {
            ideas[i++] = "idea";
        }
        std::cout << "Brain constructed\n";
    }
    Brain::Brain(const Brain &src) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = src.ideas[i];
        }
        std::cout << "Copy constructor for Brain class\n";
    }
    Brain& Brain::operator=(const Brain& src) {
        if (this != &src)
        {
            for (int i = 0; i < 100; i++)
            {
                ideas[i] = src.ideas[i];
            }
        }
        return *this;
    }

    Brain::~Brain() {
        std::cout << "Brain destructed\n";
    }

    std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "Invalid index";
    }

    // std::ostream& operator<<(std::ostream& os, const Brain& brain) {
    //     for (int i = 0; i < 100; i++) {
    //         os << "Idea# " << i << " " << brain.getIdea(i) << "\n"; // Print each idea on a new line
    //     }
    //     return os;
// }
