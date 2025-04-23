#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class Bureaucrat
{
private:
    const std::string _name;
    unsigned int _grade; // ranges from 1(highest) to 150

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const unsigned int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();

    std::string getName();
    unsigned int getGrade();
    void incrementGrade();
    void decrementGrade();
};

#endif