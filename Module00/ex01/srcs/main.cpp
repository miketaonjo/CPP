/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:52 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/05 15:22:21 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	Phonebook;

	std::cout << "Enter a command (ADD or SEARCH or EXIT) :" << std::endl;
	while (true)
	{
		std::getline (std::cin, cmd);
		if (cmd == "ADD")
			Phonebook.AddContact();
		else if (cmd == "SEARCH")
			Phonebook.PrintContact();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
