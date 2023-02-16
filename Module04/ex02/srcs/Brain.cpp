/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:54:38 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 14:58:59 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::string str = "Bienvenue à 42";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = str;
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "Brain operator= called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.getIdeas(i);
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeas(int n) const
{
	return (this->ideas[n]);
}

void Brain::setIdeas(std::string s, int n)
{
	if (n > 0 && n < 100)
		this->ideas[n] = s;
	else
		std::cout << "Out of the array range" << std::endl;
}
