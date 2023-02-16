/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:14:41 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/13 18:25:52 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource operator= constructor called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
	 		delete this->_inventory[i];
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = obj._inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				return ;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	AMateria *tmp = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i]->getType() == type)
		{
			tmp = this->_inventory[i]->clone();
			return (tmp);
		}
	}
	return (tmp);
}
