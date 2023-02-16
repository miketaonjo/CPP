/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:38 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 15:21:01 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(AAnimal const &obj);
		AAnimal &operator=(AAnimal const &obj);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;

	protected:
		std::string type;
};

#endif
