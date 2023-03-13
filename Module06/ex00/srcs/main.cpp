/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:00:12 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/24 16:50:25 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string s;

	if (argc != 2)
	{
		std::cout << "Need only one argument" << std::endl;
		return (-1);
	}
	s = argv[1];
	ScalarConverter::convert(s);
	
	return (0);
}
