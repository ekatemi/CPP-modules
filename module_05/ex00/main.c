#include "Bureaucrat.hpp"

int main(void)
{

    Bureaucrat a;
    std::cout << a << std::endl;
    //Bureaucrat b("Garry", 150);
    std::cout << std::endl;
    std::cout << "Start try/catch bloque-------->" << std::endl;
    std::cout << std::endl;

    try
    {
        Bureaucrat b("Garry", 1);
        b.incrementGrade();
        std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception cought in Bureaucrat: " << e.what() << std::endl;
    }

    return(0);
}