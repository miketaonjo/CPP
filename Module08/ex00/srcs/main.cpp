/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:16:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/10 03:38:43 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main (void)
{
	std::vector<int> array1 (3);
	std::list<int> array2;

	array1[0] = 21;
	array1[1] = 2;
	array1[2] = 16;

	for (int i = 0; i < 5; i++)
		array2.push_back(i);

	try
	{
		std::cout << "Emplacement " << std::distance(array1.begin(), easyfind(array1, 16)) << " : " << *(easyfind(array1, 16)) << " (array size : " << array1.size() << ")" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::distance(array1.begin(), easyfind(array1, 10)) << " : " << *(easyfind(array1, 10)) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Emplacement " << std::distance(array2.begin(), easyfind(array2, 3)) << " : " << *(easyfind(array2, 3)) << " (array size : " << array2.size() << ")" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::distance(array2.begin(), easyfind(array2, 21)) << " : " << *(easyfind(array2, 21)) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
