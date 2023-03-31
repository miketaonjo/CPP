/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:30:51 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 10:27:05 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &obj);
		Dog &operator=(Dog const &obj);
		void makeSound(void) const;
		const std::string &getType(void) const;

	private:
		std::string type;
		Brain *brain;
};

#endif
