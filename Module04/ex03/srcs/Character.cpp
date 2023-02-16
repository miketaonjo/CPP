/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:44:00 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/13 19:32:44 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "Anonymous";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "Character string constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &obj)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = obj;
}

Character& Character::operator=(Character const &obj)
{
	std::cout << "Character operator= constructor called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		for (int i = 0; i < 4; i++)
	 		delete this->_inventory[i];
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = obj._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
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

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
			this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
			this->_inventory[idx]->use(target);
}
