
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", target, 145, 137)
{ 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if(this != &src)
        AForm::operator=(src);
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
    std::string file_name = getTarget() + "_shrubbery";
    
    std::ofstream file(file_name);  // Create and open a file

    if (file.is_open()) {             
        file << "   /\\\n"; 
        file << "  /**\\\n";
        file << " /****\\\n";
        file << "   ||\n";
        file.close();
    } else {
        std::cout << "Error opening file!" << std::endl;
    }
}
