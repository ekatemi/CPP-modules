
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", target, 25, 5)
{ 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

//redefine base method
void PresidentialPardonForm::action() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


