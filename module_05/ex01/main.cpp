#include "Form.hpp"

int main(void)
{
    Bureaucrat a("Garry", 75);
    Form f;

    std::cout << f << std::endl;

    f.beSigned(a);
    std::cout << f << std::endl;

    return (0);
}