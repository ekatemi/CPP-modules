#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;

        Form f("Report", 100, 50);
        std::cout << f << std::endl;

        Bureaucrat a("Garry", 75);
        Form myform("Order", 70, 50);

        std::cout << myform << std::endl;

        // myform.beSigned(a);
        a.signForm(myform);
        std::cout << myform << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}