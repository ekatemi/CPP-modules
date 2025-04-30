#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
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
    const std::string _target;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_exec;
    virtual void action() const = 0; //pure abstract class

public:
    //AForm();
    AForm(std::string str, std::string target, int sign, int exec);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &src);
    virtual ~AForm();
    // methods
    std::string getName() const;
    std::string getTarget() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(const Bureaucrat &obj);
    //virtual void action() const = 0; //pure abstract class
    virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
