/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:31:25 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/13 18:11:49 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice (std::string const &type) : AMateria(type)
{
	std::cout << "Ice string constructor called" << std::endl;
	this->_type = type;
}

Ice::Ice (Ice const &obj) : AMateria(obj)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = obj;
}

Ice& Ice::operator= (Ice const &obj)
{
	std::cout << "Ice operator= constructor called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

std::string const &Ice::getType() const
{
	return (this->_type);
}

Ice *Ice::clone() const
{
	Ice *tmp = new Ice();
	return (tmp);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
