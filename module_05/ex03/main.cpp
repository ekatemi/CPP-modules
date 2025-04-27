#include "Intern.hpp"

int main(void)
{
    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Office");
    if (rrf)
        std::cout << *rrf << std::endl;
    else
        std::cout << "Form was not created\n";

    delete rrf;



    return 0;
}
