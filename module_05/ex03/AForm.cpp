
#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade is too low!";
}

//AForm::AForm() : _name("Form_def"), _signed(false), _target("def"), _grade_to_sign(150), _grade_to_exec(150) {}

AForm::AForm(std::string str, std::string target, int sign, int exec) : _name(str), _target(target), _signed(false), _grade_to_sign(sign), _grade_to_exec(exec)
{
    if (sign < 1 || exec < 1)
        throw GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &obj) : _name(obj._name), _target(obj._target), _signed(obj._signed), _grade_to_sign(obj._grade_to_sign), _grade_to_exec(obj._grade_to_exec) {

}

AForm &AForm::operator=(const AForm &src) {
    if(this != &src)
        _signed = src._signed;
    return (*this);
}

AForm::~AForm() {}

int AForm::getGradeToExec() const
{
    return (_grade_to_exec);
}

int AForm::getGradeToSign() const
{
    return (_grade_to_sign);
}

std::string AForm::getName() const
{
    return (_name);
}

std::string AForm::getTarget() const {
    return (_target);
}

bool AForm::isSigned() const
{
    return (_signed);
}

void AForm::beSigned(const Bureaucrat &obj)
{

    if (obj.getGrade() <= getGradeToSign())
    {
        _signed = true;
    }
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {
    if (isSigned() && executor.getGrade() <= getGradeToExec())
        action();
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned() << ", grade req to sign: " << obj.getGradeToSign() << ", grade to exec: " << obj.getGradeToExec();
    return os;
}
