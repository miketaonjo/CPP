/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:58:39 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 18:41:11 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat one("one", 1);
	Bureaucrat two("two", 150);
	ShrubberyCreationForm f1("Forest");
	RobotomyRequestForm f2("Wall-E");
	PresidentialPardonForm f3("Toto");

	std::cout << one << std::endl;
	std::cout << two << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << std::endl;

	one.signForm(f1);
	one.signForm(f2);
	one.signForm(f3);
	std::cout << std::endl;

	one.executeForm(f1);
	one.executeForm(f2);
	one.executeForm(f3);
	std::cout << std::endl;

	two.signForm(f1);
	two.signForm(f2);
	two.signForm(f3);
	std::cout << std::endl;

	two.executeForm(f1);
	two.executeForm(f2);
	two.executeForm(f3);

	return (0);
}
