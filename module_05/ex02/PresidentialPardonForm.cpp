
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", target, 25, 5)
{ 
}

void PresidentialPardonForm::action() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


