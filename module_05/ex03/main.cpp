#include "Intern.hpp"

int main(void)
{
    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    if (rrf)
        std::cout << *rrf << std::endl;
    else
        std::cout << "Form was not created\n";

    try
    {
        Bureaucrat a("Tom", 72);
        a.signForm(*rrf);
        std::cout << *rrf << std::endl;
        a.executeForm(*rrf);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
    
    delete rrf;
    return 0;
}
