/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:29:40 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/24 09:31:06 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	std::cout << "randomChump:\n";
	randomChump("Roamers");
	std::cout << "newZombie:\n";
	Zombie *dead = newZombie("Creepers");
	dead->announce();
	delete dead;
	return (0);
}
