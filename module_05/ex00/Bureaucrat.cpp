#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {};

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : _name(name) {

                                                                            };
Bureaucrat::Bureaucrat(const Bureaucrat &src) {};
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {};
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