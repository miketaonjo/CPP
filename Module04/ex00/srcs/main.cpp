/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:03:06 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 09:08:09 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* one = new Animal();
	const Animal* two = new Cat();
	const Animal* three = new Dog();
	const WrongAnimal* four = new WrongCat();

	std::cout << one->getType() << " " << std::endl;
	std::cout << two->getType() << " " << std::endl;
	std::cout << three->getType() << " " << std::endl;
	std::cout << four->getType() << " " << std::endl;
	two->makeSound();
	three->makeSound();
	one->makeSound();
	four->makeSound();

	delete one;
	one = NULL;
	delete two;
	two = NULL;
	delete three;
	three = NULL;
	delete four;
	four = NULL;
  
	return (0);
}
