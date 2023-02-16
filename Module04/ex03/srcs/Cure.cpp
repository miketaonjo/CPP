/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:02:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/13 18:28:08 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria()
{
	std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure (std::string const &type) : AMateria(type)
{
	std::cout << "Cure string constructor called" << std::endl;
	this->_type = type;
}

Cure::Cure (Cure const &obj) : AMateria(obj)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = obj;
}

Cure& Cure::operator= (Cure const &obj)
{
	std::cout << "Cure operator= constructor called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

std::string const &Cure::getType() const
{
	return (this->_type);
}

Cure *Cure::clone() const
{
	Cure *tmp = new Cure();
	return (tmp);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
