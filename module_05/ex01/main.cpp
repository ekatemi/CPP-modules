#include "Form.hpp"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int main(void)
{
    try
    {
        //Bureaucrat c;
        //std::cout << c << std::endl;
        Bureaucrat b("Yen", 100);
        std::cout << b << std::endl;

        //c.decrementGrade();//throw exception Grade is too low
            

        Form f("Report", 100, 100);

        Bureaucrat a("Garry", 75);
        std::cout << a << std::endl;
        Form myform("Order", 70, 100);

        std::cout << myform << std::endl;

        std::cout << GREEN << "Is " << b.getName() << " able to sign form " << f.getName() << "?" << RESET << std::endl;
        std::cout << f << std::endl;
        f.beSigned(b);
        std::cout << f << std::endl;
        std::cout << GREEN << b.getName() << " is signing form " << f.getName() << RESET << std::endl;
        b.signForm(f);
        std::cout << GREEN << "Is " << b.getName() << " able to sign form " << myform.getName() << "?" << RESET << std::endl;
        b.signForm(myform);
        std::cout << myform << std::endl;
        throw 42;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (int)
    {
        std::cerr << "Other Exception caught" << std::endl;
    }
        
    return 0;
}
