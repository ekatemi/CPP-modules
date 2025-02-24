
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : idx(0) {
    for(int i = 0; i < 4; i++)
        materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) : idx(src.idx) {
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
        idx = src.idx;
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

// Learn Materia: Copy and store
void MateriaSource::learnMateria(AMateria* m) {
    if (!m)  // Check if the passed Materia is valid
        return;

    // Check for an empty slot
    for (int i = 0; i < 4; i++) {
        if (materia[i] == NULL) {  // Find the first empty slot
            materia[i] = m->clone();  // Clone the Materia
            delete m;
            return;
        }
    }

    // All slots are full, replace Materia in a loop starting from idx
    delete materia[idx];  // Free old Materia
    materia[idx] = m->clone();  // Clone new Materia
    delete m;
    idx = (idx + 1) % 4;  // Move index cyclically from 0 to 3
}

// Create Materia: Return a clone of a learned Materia
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materia[i] && materia[i]->getType() == type) {  // Check if not NULL
            return materia[i]->clone();  // Return a new copy
        }
    }
    return NULL;  // Return NULL if type is unknown
}



