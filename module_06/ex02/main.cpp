#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

Base *generate(void)
{
    std::srand(static_cast<unsigned>(std::time(NULL))); // Initialize random seed using current time
    int rand1 = rand() % 101;

    if (rand1 % 2 == 0)
    {
        A *a = new A;
        return dynamic_cast<Base *>(a);
    }
    else if (rand1 % 3 == 0)
    {
        B *b = new B;
        return dynamic_cast<Base *>(b);
    }
    else if (rand1 % 2 != 0)
    {
        C *c = new C;
        return dynamic_cast<Base *>(c);
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "It is A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "It is B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "It is C" << std::endl;
    }
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "It is A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "It is B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "It is C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    Base *p = generate();

 
    identify(*p);
    delete p;
    return (0);
}