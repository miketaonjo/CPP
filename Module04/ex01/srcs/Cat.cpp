/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:49:08 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 14:57:32 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = obj.type;
	this->brain = new Brain(*(obj.brain));
}

Cat& Cat::operator=(const Cat& obj) 
{
	std::cout << "Cat operator= called" << std::endl;
	this->type = obj.type;
	*(this->brain) = *(obj.brain);
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	brain = NULL;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow ~" << std::endl;
}
