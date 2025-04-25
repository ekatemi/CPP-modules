#include "Bureaucrat.hpp"

int main(void)
{

    Bureaucrat a;
    std::cout << a << std::endl;
    Bureaucrat b("Garry", 150);

    try
    {
        //Bureaucrat b("Garry", 150);
        for (int i; i < 80; i++)
            b.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception cought: " << e.what() << std::endl;
    }
    std::cout << b << std::endl;

    return(0);
}