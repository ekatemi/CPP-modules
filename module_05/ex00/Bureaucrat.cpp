#include "Bureaucrat.hpp"

GradeTooHighException::GradeTooHighException() : _error("Grade too high") {};
std::string GradeTooHighException::getError() { return _error; };

GradeTooLowException::GradeTooLowException() : _error("Grade too low") {};
std::string GradeTooLowException::getError() { return _error; };

Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {};

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        _name = src._name;
        _grade = src._grade;
    }
    return *this;
};

Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName()
{
    return _name;
};
unsigned int Bureaucrat::getGrade()
{
    return _grade;
};

void Bureaucrat::incrementGrade()
{
    _grade--;
};

void Bureaucrat::decrementGrade()
{
    _grade++;
};