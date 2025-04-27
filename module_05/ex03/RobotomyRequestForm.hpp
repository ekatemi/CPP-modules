#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
    void action() const;
    
    public:
    RobotomyRequestForm(std::string target);
    //ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    
    //method
    
   
    
    
};

//std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);

#endif
