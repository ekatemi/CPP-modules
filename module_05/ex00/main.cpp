#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat a("Garry", 75);
    std::cout << a << std::endl;
    // for (int i = 0; i < 200; i++)
    //     a.incrementGrade();
    try
    {
        for (int i = 0; i < 20; i++)
            a.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        for (int i = 0; i < 10; i++)
            a.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    // this code executing after catch block
    std::cout << a << std::endl;

    return (0);
}