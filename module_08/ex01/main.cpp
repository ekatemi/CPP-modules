#include "Span.hpp"
int main()
{
    std::cout << "\033[32m*** Test 1: Subject test ***\033[0m" << std::endl;
    try
    {
        Span sp = Span(5);
        std::cout << sp << std::endl;
        sp.addNumber(6);
        sp.addNumber(-3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        //sp.addNumber(8); //throw error
        std::cout << "\033[32m* What contains vector *\033[0m" << std::endl;
        sp.printNum();
        std::cout << sp << std::endl;
        //output
        std::cout << "\033[32m* Shortest and longest span *\033[0m" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error in subject test: " << e.what() << '\n';
    }
    std::cout << "\033[32m*** Test 2 big number and add random range***\033[0m" << std::endl;
    try
    {
        Span sp = Span(1000000);
        std::cout << sp << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        std::cout << sp << std::endl;
        sp.addRandomRange();
        std::cout << sp << std::endl;
        //sp.printNum(); //uncomment!
        //sp.addNumber(3); //overflow exception
        std::cout << "\033[32m* Shortest and longest span *\033[0m" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error in test 2: " << e.what() << '\n';
    }
    std::cout << "\033[32m*** Test 3 modified add number ***\033[0m" << std::endl;
    try
    {
        Span sp = Span(3);
        std::cout << sp << std::endl;
        int arr[] = {1, 2, 3, 50, 30, 43, 12, 18, 78, 0, -5};
        std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
        sp.addNumber(6);
        sp.addNumber(3);
        sp.printNum();
        std::cout << sp << std::endl;
        sp.addRange(v);
        std::cout << sp << std::endl;
        std::cout << "this should be the same as next" <<std::endl;
        sp.printNum();
        sp.addArray(arr, sizeof(arr));
        sp.printNum();
        //sp.addNumber(3); //overflow exception
        std::cout << "\033[32m* Shortest and longest span *\033[0m" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error in test 3: " << e.what() << '\n';
    }
    return 0;
}