/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:58:39 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/17 11:36:17 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	Bureaucrat a("a", 1);
	Bureaucrat b("b", 150);
	Intern someRandomIntern;
	AForm *rrf;
	AForm *rrf2;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	a.signForm(*rrf);
	std::cout << *rrf << std::endl;
	a.executeForm(*rrf);
	delete rrf;

	rrf2 = someRandomIntern.makeForm("shruberry creation", "Olaf");
	b.signForm(*rrf2);
	std::cout << *rrf2 << std::endl;
	b.executeForm(*rrf2);
	delete rrf2;

	return (0);
}
