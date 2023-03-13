/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:26 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/15 15:23:19 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	try
	{
		try
		{
			Bureaucrat test("test", 151);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		Bureaucrat one("one", 1);
		Bureaucrat two("two", 150);
		std::cout << one << std::endl;
		std::cout << two << std::endl;
		
		one.incrementGrade();
		two.decrementGrade();
		std::cout << one << std::endl;
		std::cout << two << std::endl;
		
		one.decrementGrade();
		two.incrementGrade();
		std::cout << one << std::endl;
		std::cout << two << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
