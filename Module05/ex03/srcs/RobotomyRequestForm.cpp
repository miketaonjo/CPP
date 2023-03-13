/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:49:11 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 19:36:33 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
	this->_target = "Anonymous";
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	this->_target = target;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : AForm(obj)
{
	*this = obj;
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this != &obj)
	{
		this->_target = obj._target;
		this->AForm::operator=(obj) = obj;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

void RobotomyRequestForm::execute(Bureaucrat const &one) const
{
	srand(time(0));
	this->checkExecute(one);
	std::cout << "brrrrrrrrrrrrrrrr" << std::endl;
	if (rand() % 2 != 1)
		std::cout << this->_target << " becomed a robot !" << std::endl;
	else
		std::cout << this->_target << " failed to become a robot !" << std::endl;
	// srand(time(0));
	// std::cout << "brrrrrrrrrrrrrrrr" << std::endl;
	// try
	// {
	// 	this->checkExecute(one);
	// 	if (rand() % 2 != 1)
	// 			std::cout << this->_target << " becomed a robot !" << std::endl;
	// 	else
	// 		std::cout << this->_target << " failed to become a robot !" << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << this->_target << " cannot become a robot" << std::endl;
	// }
}
