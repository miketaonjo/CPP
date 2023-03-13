/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:29:52 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 19:35:31 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high...");
}

const char *AForm::GradeTooLowException::what(void) const throw() 
{
	return ("Grade is too low...");
}

AForm::AForm(void) : _name("Anonymous"), _gradeToSign(0), _gradeToExec(0)
{
    this->_signed = false;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _gradeToSign(signGrade), _gradeToExec(execGrade)
{
    this->_signed = false;
	if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
	else if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
}

AForm::AForm(AForm const &obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
    *this = obj;
}

AForm& AForm::operator=(AForm const &obj)
{
	if (this != &obj)
	    this->_signed = obj._signed;
	return (*this);
}

AForm::~AForm(void)
{
    return ;
}

const std::string& AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void AForm::beSigned(Bureaucrat const &one)
{
	if (this->_gradeToSign >= one.getGrade())
		this->_signed = true;
	else
		throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName() <<", signed : " << form.getSigned() << ", gradeToSign : " << form.getGradeToSign() << ", gradeToExec : " << form.getGradeToExec();
	return (out);
}

void AForm::checkExecute(Bureaucrat const &one) const
{
	if (this->_gradeToExec <= one.getGrade() || this->_signed == false)
		throw AForm::GradeTooLowException();
}
