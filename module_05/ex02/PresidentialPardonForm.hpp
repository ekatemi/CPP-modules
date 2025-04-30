#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

    private:
        void action() const;
    public:
    //PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
    ~PresidentialPardonForm();
};

#endif
