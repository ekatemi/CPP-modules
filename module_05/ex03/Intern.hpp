#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    
    public:
    Intern();
    Intern(std::string name);
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();

    AForm *makeForm(std::string name, std::string target);
};

#endif
