#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class GradeTooHighException
{
private:
    std::string _error;

public:
    GradeTooHighException();
    std::string getError();
};

class GradeTooLowException
{
private:
    std::string _error;

public:
    GradeTooLowException();
    std::string getError();
};

class Bureaucrat
{
private:
    const std::string _name;
    int _grade; // ranges from 1(highest) to 150

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();

    std::string getName();
    unsigned int getGrade();
    void incrementGrade();
    void decrementGrade();
};

#endif