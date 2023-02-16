/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:12:00 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/30 18:51:52 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
{
	this->_name = "Anonymous";
	this->_hit_pts = 10;
	this->_energy_pts = 10;
	this->_attack_dmg = 0;
	std::cout << "Default constructor called" << std::endl;	
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hit_pts = 10;
	this->_energy_pts = 10;
	this->_attack_dmg = 0;
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_hit_pts = obj._hit_pts;
		this->_energy_pts = obj._energy_pts;
		this->_attack_dmg = obj._attack_dmg;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energy_pts != 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage!" << std::endl;
	}
	else
		std::cout << "No more energy points, cannot execute any action !" << std::endl;
	this->_energy_pts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
		std::cout << "ClapTrap cannot take damage because it's already dead!" << std::endl;
	else if (this->_hit_pts - amount <= 0)
		std::cout << "ClapTrap died!" << std::endl;
	else
	{
		this->_hit_pts = this->_hit_pts - amount;
		std::cout << "ClapTrap " << this->_name << " lost " << amount << " hit points!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts != 0)
	{
		this->_hit_pts = this->_hit_pts + amount;
		std::cout << "ClapTrap " << this->_name << " restored " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "No more energy points, cannot execute any action !" << std::endl;
	this->_energy_pts--;
}
