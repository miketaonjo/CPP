/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 18:03:49 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high...";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low...";
}

Bureaucrat::Bureaucrat(void) : _name("Anonymous")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj.getName())
{
	*this = obj;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
    {
	    this->_grade = obj._grade;
	    if (this->_grade < 1)
		    throw Bureaucrat::GradeTooHighException();
	    else if (this->_grade > 150)
    		throw Bureaucrat::GradeTooLowException();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &one)
{
	out << one.getName() << ", bureaucrat grade " << one.getGrade();
	return (out);
}
