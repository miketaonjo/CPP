/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:30:01 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 09:48:33 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat one("one", 1);
		Bureaucrat two("two", 150);
		Form form("form", 42, 1);

		std::cout << one << std::endl;
		std::cout << two << std::endl;
		std::cout << form << std::endl;
		one.signForm(form);
		std::cout << std::endl;
		
		std::cout << one << std::endl;
		std::cout << two << std::endl;
		std::cout << form << std::endl;
		two.signForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
