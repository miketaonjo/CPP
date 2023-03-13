/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:07:53 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/25 17:10:29 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
	Data one;
	Data *two;
	uintptr_t ptr;

	one.name = "Toto";
	std::cout << "one : " << one.name << std::endl;
	ptr = Serializer::serialize(&one);
	std::cout << "ptr : " << ptr << std::endl;
	two = Serializer::deserialize(ptr);
	std::cout << "two : " << two->name << std::endl;
	return (0);
}
