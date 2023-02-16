/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:31:36 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 15:22:50 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &obj);
		Cat &operator=(Cat const &obj);
		void makeSound(void) const;
		const std::string &getType(void) const;

	private:
		std::string type;
		Brain *brain;
};

#endif
