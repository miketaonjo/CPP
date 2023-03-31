/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:52:09 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 14:44:45 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = obj.type;
	this->brain = new Brain(*(obj.brain));
}

Dog& Dog::operator=(const Dog& obj) 
{
	std::cout << "Dog operator= called" << std::endl;
	this->type = obj.type;
	*(this->brain) = *(obj.brain);
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	brain = NULL;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}
