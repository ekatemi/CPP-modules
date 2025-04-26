#include "ShrubberyCreationForm.hpp"

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    // Continuing with other code, assuming Bureaucrat creation was successful
    try
    {
        // Create other forms
        Bureaucrat b("Will", 1);
        PresidentialPardonForm p("Trish");
        ShrubberyCreationForm s("Office");
        RobotomyRequestForm r("Bender");

        // Output form details
        std::cout << p << std::endl;
        std::cout << s << std::endl;
        std::cout << r << std::endl;

        // Bureaucrat signs the forms
        b.signForm(p);
        b.signForm(s);
        b.signForm(r);

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
        // Catching exceptions for signing or executing the forms
        std::cerr << "Error with form operation: " << e.what() << '\n';
    }

    return 0;
}
