/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:05:33 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/10 18:27:08 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(void) 
{
	this->_type = "unknown";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) 
{
	std::cout << "AMateria string constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &obj)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=(AMateria const &obj) 
{
	std::cout << "AMateria operator= called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria::~AMateria(void) 
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "Something's wrong because this is an abstract class" << std::endl;
}
