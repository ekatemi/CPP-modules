#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    private:
    typedef AForm* (*funcPtr)(std::string target);
    static AForm* createShrubberyForm(std::string target);
    static AForm* createRobotomyForm(std::string target);
    static AForm* createPardonForm(std::string target);
    
    public:
    Intern();
    Intern(std::string name);
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();

    AForm *makeForm(std::string name, std::string target);
};

#endif
