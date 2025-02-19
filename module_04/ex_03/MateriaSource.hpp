#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Amateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    protected:
        AMateria *materia[4];
        int idx;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator=(const MateriaSource& src);
        ~MateriaSource();

        void learnMateria(AMateria*); //pointer to object AMateria
        AMateria* createMateria(std::string const & type);
};

#endif
