#include <iostream>
#include <string>

int main(void) {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Address of string is:    " << &string << std::endl;
    std::cout << "Address of stringPTR is: " << stringPTR << std::endl;
    std::cout << "Address of stringREF is: " << &stringREF << std::endl;

    std::cout << "The value of string is:    " << string << std::endl;
    std::cout << "The value of stringPTR is: " << *stringPTR << std::endl;
    std::cout << "The value of stringREF is: " << stringREF << std::endl;

    return (0);
}
