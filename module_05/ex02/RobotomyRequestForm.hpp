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
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
    ~RobotomyRequestForm();
    
   
    
    
};

//std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);

#endif
