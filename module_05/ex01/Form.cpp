
#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}
const std::string _name;
bool _signed;
Form::Form() : _name("Form_def"), _signed(false), _grade_to_sign(150), _grade_to_exec(150) {};

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned() << ", grade req: " << obj.getGradeToSign() << ", grade to exec: " << obj.getGradeToExec();
    return os;
}
