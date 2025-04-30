#include "ShrubberyCreationForm.hpp"

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        // Create other forms
        Bureaucrat b("Will", 45);
        Bureaucrat c = b;
        PresidentialPardonForm p("Trish");
        ShrubberyCreationForm s("Office");
        RobotomyRequestForm r("Bender");

        // Output form details
        std::cout << p << std::endl;
        std::cout << s << std::endl;
        std::cout << r << std::endl;

        // Bureaucrat signs the forms
        c.signForm(p);
        c.signForm(s);
        c.signForm(r);

        // Output updated form details
        std::cout << p << std::endl;
        std::cout << s << std::endl;
        std::cout << r << std::endl;

        // Bureaucrat executes the forms
        b.executeForm(p);
        b.executeForm(s);
        b.executeForm(r);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}
