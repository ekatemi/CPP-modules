
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{ 
}

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


