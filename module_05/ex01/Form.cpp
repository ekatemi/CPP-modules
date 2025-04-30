
#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade is too low!";
}

Form::Form() : _name("Form_def"), _signed(false), _grade_to_sign(150), _grade_to_exec(150) {}

Form::Form(std::string str, int sign, int exec) : _name(str), _signed(false), _grade_to_sign(sign), _grade_to_exec(exec)
{
    if (sign < 1 || exec < 1)
        throw GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &obj) : _name(obj._name), _signed(obj._signed), _grade_to_sign(obj._grade_to_sign), _grade_to_exec(obj._grade_to_exec) {

}

Form &Form::operator=(const Form &src) {
    if(this != &src)
        _signed = src._signed;
    return (*this);
}

Form::~Form() {}

int Form::getGradeToExec() const
{
    return (_grade_to_exec);
}

int Form::getGradeToSign() const
{
    return (_grade_to_sign);
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_signed);
}

void Form::beSigned(const Bureaucrat &obj)
{

    if (obj.getGrade() <= getGradeToSign())
    {
        _signed = true;
    }
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned() << ", grade required to sign: " << obj.getGradeToSign() << ", grade to exec: " << obj.getGradeToExec();
    return os;
}
