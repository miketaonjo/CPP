/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:49:02 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 19:36:04 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include <exception>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
	this->_target = "Anonymous";
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5)
{
	this->_target = target;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj)
{
	*this = obj;
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	if (this != &obj)
    {
	    this->_target = obj._target;
	    this->AForm::operator=(obj) = obj;
    }
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

void PresidentialPardonForm::execute(Bureaucrat const &one) const
{
	this->checkExecute(one);
	std::cout << this->_target  << " was pardoned by President Zaphod Beeblebrox" << std::endl;
	// try
	// {
	// 	this->checkExecute(one);
	// 	std::cout << this->_target  << " was pardoned by President Zaphod Beeblebrox" << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << this->_target << " is either unsigned or " << one.getName() << " grade's is too low" << std::endl;
	// }
}
