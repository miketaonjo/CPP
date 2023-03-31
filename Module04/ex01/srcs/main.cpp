/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:03:06 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 15:01:07 by mcloarec         ###   ########.fr       */
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
	const Animal* one = new Cat();
	const Animal* two = new Dog();

	delete one;
	one = NULL;
	delete two;
	two = NULL;
  
	int n = 4;
	Animal **array = new Animal*[n];
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
