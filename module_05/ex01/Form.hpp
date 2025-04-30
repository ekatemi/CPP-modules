#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_exec;

public:
    Form();
    Form(std::string str, int sign, int exec);
    Form(const Form &obj);
    Form &operator=(const Form &src);
    ~Form();
    // methods
    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
