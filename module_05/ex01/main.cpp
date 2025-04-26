#include "Form.hpp"

int main(void)
{
    Bureaucrat b("Bob", 120);
    std::cout << b << std::endl;
    Form f("Report", 100, 50);

    b.signForm(f);


    Bureaucrat c(b);
    // c.decrementGrade(-10);
    // std::cout << c << std::endl;
    
    try
    {
        
        Bureaucrat b("Bob", 1);
        std::cout << b << std::endl;

            c.decrementGrade(-10);
            

        Form f("Report", 100, 50);
        std::cout << f << std::endl;

        Bureaucrat a("Garry", 75);
        std::cout << a << std::endl;
        Form myform("Order", 70, 50);

        std::cout << myform << std::endl;

        //myform.beSigned(a);
        a.signForm(myform);
        a.signForm(f);
        b.signForm(f);
        b.signForm(myform);
        //std::cout << myform << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
std::cout << c << std::endl;
    return 0;
}
