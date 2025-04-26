#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
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
    const std::string _name; // unmutable
    unsigned int _grade;     // ranges from 1(highest) to 150
    Bureaucrat &operator=(const Bureaucrat &src);

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const unsigned int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &a) const;
    void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
