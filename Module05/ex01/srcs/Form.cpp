/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:29:52 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 09:46:05 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high...");
}

const char *Form::GradeTooLowException::what(void) const throw() 
{
	return ("Grade is too low...");
}

Form::Form(void) : _name("Anonymous"), _gradeToSign(0), _gradeToExec(0)
{
    this->_signed = false;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _gradeToSign(signGrade), _gradeToExec(execGrade)
{
    this->_signed = false;
	if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
	else if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
}

Form::Form(Form const &obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
    *this = obj;
}

Form& Form::operator=(Form const &obj)
{
	if (this != &obj)
	    this->_signed = obj._signed;
	return (*this);
}

Form::~Form(void)
{
    return ;
}

const std::string& Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void Form::beSigned(Bureaucrat const &one)
{
	if (this->_gradeToSign >= one.getGrade())
		this->_signed = true;
	else
		throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() <<", signed : " << form.getSigned() << ", gradeToSign : " << form.getGradeToSign() << ", gradeToExec : " << form.getGradeToExec();
	return (out);
}
