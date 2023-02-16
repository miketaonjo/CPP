/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:54:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 07:56:50 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) 
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) 
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj) 
{
	std::cout << "WrongAnimal operator= called" << std::endl;
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Can't identify the sound of WrongAnimal" << std::endl;
}
