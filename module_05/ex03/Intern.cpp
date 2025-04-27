#include "Intern.hpp"


Intern::Intern() {}
Intern::Intern(std::string name) { (void)name; }
Intern::Intern(const Intern &src) {(void)src;  }
Intern &Intern::operator=(const Intern &src) { 
    if (this != &src)
    {
        return *this;
    }
    return *this; }

Intern::~Intern() {}

AForm *Intern::createShrubberyForm(std::string target) { return new ShrubberyCreationForm(target);}
AForm *Intern::createRobotomyForm(std::string target) { return new RobotomyRequestForm(target);}
AForm *Intern::createPardonForm(std::string target) { return new PresidentialPardonForm(target); }




AForm* Intern::makeForm(std::string name, std::string target) {
    std::string arr[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    funcPtr fun[] = {&Intern::createPardonForm, &Intern::createRobotomyForm, &Intern::createShrubberyForm};
    for(int i = 0; i < 3; i++)
    {
        if(arr[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return fun[i](target);
        }
        }
        
        std::cout << "Form can not be created, wrong name: " << name << std::endl;
        return NULL;

} 


// AForm* Intern::makeForm(std::string name, std::string target)
// {
//     std::string arr[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

//     for(int i = 0; i < 3; i++)
//     {
//         if (arr[i] == name){
//             std::cout << "Intern creates " << name << std::endl;
//             switch (i)
//             {
//             case 0:
//                 return (new PresidentialPardonForm(target));
//             case 1:
//                 return (new RobotomyRequestForm(target));
//             default:
//                 return (new ShrubberyCreationForm(target));
//             }         
//         }
//     }
//     std::cout << "Form can not be created, wrong name: " << name << std::endl;
//     return NULL;
// }
