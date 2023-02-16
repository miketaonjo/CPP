/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:03:06 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/10 15:11:59 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	//const AAnimal* meta = new AAnimal();
	const AAnimal* one = new Cat();
	const WrongAnimal* two = new WrongCat();

	one->makeSound();
	two->makeSound();

	delete one;
	one = NULL;
	delete two;
	two = NULL;
  
	int n = 4;
	AAnimal **array = new AAnimal*[n];
	for (int i = 0; i < (n / 2); i++)
		array[i] = new Cat();
	for (int i = (n / 2); i < n; i++)
		array[i] = new Dog();
	for(int i = 0; i < n; i++)
		array[i]->makeSound();
	for (int i = 0; i < n; i++)
	{
		delete array[i];
		array[i] = 0;
	}
	delete [] array;
	return (0);
}
