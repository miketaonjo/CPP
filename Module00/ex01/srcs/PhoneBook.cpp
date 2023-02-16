/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:43:34 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/05 18:28:52 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->nb_contact = 0;
	return ;
}

void	PhoneBook::AddContact(void)
{
	this->index++;
	nb_contact++;
	if (this->index > 8)
	{
		this->index = 1;
		nb_contact--;
	}
	if (this->index > 0)
		this->contacts[this->index].AddContact();
}

void	PhoneBook::PrintContact(void)
{
	int			i;
	std::string	s;
	int			nb;
	int			check;

	i = 1;
	if (this->index == 0)
	{
		std::cout << "No contact found" << std::endl;
		return ;
	}
	std::cout << "     Index" << "|" << "First name" << "|" << " Last name" << "|" << "  Nickname" << "|" << std::endl;
	while (i <= nb_contact && i <= 8)
	{
		std::cout << "         " << i;
		this->contacts[i].PrintCondensed();
		i++;
	}
	check = 0;
	i = 0;
	nb = 0;
	std::cout << "Please enter a number to found contact" << std::endl;
	std::cin >> s;
	while (i < (int)s.length())
	{
		check = isdigit(s[i]);
		if (!check)
		{
			std::cout << "Incorrect index" << std::endl;
			return ;
		}
		else
			nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (nb < 1 || nb > nb_contact)
	{
		std::cout << "No matches" << std::endl;
		return ;
	}
	else if (nb > 0 && nb <= 8)
		contacts[nb].PrintContact();
	else
	 	std::cout << "Maximum 8 contacts registered" << std::endl;
}
