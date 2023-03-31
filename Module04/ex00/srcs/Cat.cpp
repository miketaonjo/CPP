/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:49:08 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 08:14:58 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = obj.type;
}

Cat& Cat::operator=(const Cat& obj) 
{
	std::cout << "Cat operator= called" << std::endl;
	this->type = obj.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow ~" << std::endl;
}
