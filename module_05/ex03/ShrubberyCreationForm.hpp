#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        void action() const;
    public:
        ShrubberyCreationForm(std::string target);
    //ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    

    
    
};

//std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);

#endif
