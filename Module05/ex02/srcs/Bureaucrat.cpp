/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 19:38:31 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high...");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low...");
}

Bureaucrat::Bureaucrat(void) : _name("Anonymous")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj.getName())
{
	*this = obj;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
    {
	    this->_grade = obj._grade;
	    if (this->_grade < 1)
		    throw (Bureaucrat::GradeTooHighException());
	    else if (this->_grade > 150)
    		throw (Bureaucrat::GradeTooLowException());
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
	int i = this->_grade - 1;

	if (i < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = i;
}

void Bureaucrat::decrementGrade(void)
{
	int i = this->_grade + 1;

	if (i > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = i;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &one)
{
	out << one.getName() << ", bureaucrat grade " << one.getGrade();
	return (out);
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << this->_name << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->_name << " cannot execute " << form.getName() << std::endl;
	}
}
