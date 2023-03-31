/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:45:57 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/10 14:41:57 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

AAnimal::AAnimal(void) 
{
	this->type = "AAnimal";
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj) 
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = obj.type;
}

AAnimal& AAnimal::operator=(const AAnimal &obj) 
{
	std::cout << "AAnimal operator= called" << std::endl;
	this->type = obj.type;
	return (*this);
}

AAnimal::~AAnimal(void) 
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (type);
}
