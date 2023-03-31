/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:38 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 07:47:58 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(Animal const &obj);
		Animal &operator=(Animal const &obj);
		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string type;
};

#endif
