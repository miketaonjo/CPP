/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:43:16 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/05 10:32:24 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void	Contact::AddContact(void)
{
	if (!this->firstname.empty())
	{
		this->firstname.erase(0);
		this->lastname.erase(0);
		this->nickname.erase(0);
		this->phonenumber.erase(0);
		this->darkestsecret.erase(0);
	}
	while (this->firstname.empty())
	{
		std::cout << "First name :" << std::endl;
		std::getline (std::cin, this->firstname);
	}
	while (this->lastname.empty())
	{
		std::cout << "Last name :" << std::endl;
		std::getline (std::cin, this->lastname);
	}
	while (this->nickname.empty())
	{
		std::cout << "Nickname :" << std::endl;
		std::getline (std::cin, this->nickname);
	}
	while (this->phonenumber.empty())
	{
		std::cout << "Phone number :" << std::endl;
		std::getline (std::cin, this->phonenumber);
	}
	while (this->darkestsecret.empty())
	{
		std::cout << "Darkest secret :" << std::endl;
		std::getline (std::cin, this->darkestsecret);
	}
	std::cout << "Contact saved." << std::endl;
}

void	Contact::PrintContact(void)
{
	std::cout << "First name : " << this->firstname << std::endl;
	std::cout << "Last name : " << this->lastname << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phonenumber << std::endl;
	std::cout << "Darkest secret : " << this->darkestsecret << std::endl;
}

std::string Contact::condensed(std::string str)
{
	if ((int)str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (std::string(10 - (int)str.length(), ' ') + str);
}

void	Contact::PrintCondensed(void)
{
	std::cout << "|" << condensed(this->firstname) << "|" << condensed(this->lastname) << "|" << condensed(this->nickname) << "|" << std::endl;
}
