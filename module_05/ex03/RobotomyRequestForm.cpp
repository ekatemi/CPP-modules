
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", target, 72, 45)
{ 
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

//redef parent method
void RobotomyRequestForm::action() const
{
    std::cout << "Some drilling noises...." << std::endl;
    std::srand(std::time(0));  // Initialize random seed using current time

    if (std::rand() % 2 == 0) {
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    }
    else
         std::cout << "Oh no, robotomy failed!" << std::endl;
    
}


