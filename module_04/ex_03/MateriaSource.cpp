
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
    for(int i = 0; i < 4; i++)
        materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
    for (int i = 0; i < 4; i++) {
        if (src.materia[i]) // Check if there is an AMateria in the slot
            materia[i] = src.materia[i]->clone(); // Clone creates a new copy
        else
            materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
    if (this != &src)
    {
    
    // Free existing memory to prevent memory leaks
    for (int i = 0; i < 4; i++) {
        if (materia[i]) {
            delete materia[i];
            materia[i] = NULL;
        }
    }

    // Deep copy the new inventory
    for (int i = 0; i < 4; i++) {
        if (src.materia[i]) // If the source has an item, clone it
            materia[i] = src.materia[i]->clone();
        else
            materia[i] = NULL;
    }

    }
    return *this;
}
     
MateriaSource::~MateriaSource() {
        for (int i = 0; i < 4; i++) {
        if (materia[i]) {
            delete materia[i];  // Free each dynamically allocated AMateria
            materia[i] = NULL;  // Set to NULL to avoid dangling pointers
        }
    }
}

// void MateriaSource::learnMateria(AMateria*) {

// }
// AMateria* MateriaSource::createMateria(std::string const & type) {

// }



