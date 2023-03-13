/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:46:09 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/17 11:09:41 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const &obj)
{
	(void)obj;
}

Intern& Intern::operator=(Intern const &obj)
{
	(void)obj;
    return (*this);
}

Intern::~Intern(void)
{
	return ;
}

AForm *Intern::makeForm(std::string s1, std::string s2) 
{
	std::string form[3] = {"robotomy request", "shruberry creation", "presidential pardon"};
	AForm *tmp = NULL;

	int type = -1;

	for (int i = 0; i < 3; i++)
	{
		if (form[i] == s1)
		{
			type = i;
			break;
		}
	}
	switch (type)
	{
		case 0:
			tmp = new RobotomyRequestForm(s2);
			std::cout << "Intern creates " << s1 << std::endl;
			break ;
		case 1:
			tmp = new ShrubberyCreationForm(s2);
			std::cout << "Intern creates " << s1 << std::endl;
			break;
		case 2:
			tmp = new PresidentialPardonForm(s2);
			std::cout << "Intern creates " << s1 << std::endl;
			break;
		default:
			std::cout << "No matches found" << std::endl;
			break;
	}
	return (tmp);
}
