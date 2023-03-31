/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:45:57 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 09:57:39 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void) 
{
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &obj) 
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = obj.type;
}

Animal& Animal::operator=(const Animal &obj) 
{
	std::cout << "Animal operator= called" << std::endl;
	this->type = obj.type;
	return (*this);
}

Animal::~Animal(void) 
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (type);
}

void Animal::makeSound(void) const
{
	std::cout << "Can't identified the sound of this Animal" << std::endl;
}
