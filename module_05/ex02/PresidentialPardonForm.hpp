#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

    private:
        void action() const;
    public:
    PresidentialPardonForm(std::string target);
    //ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    
    
  
    
};

//std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);

#endif
