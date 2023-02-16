/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:47 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/30 15:13:31 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap one("One");
	ClapTrap two(one);
	ClapTrap three;

	three = two;

	one.attack("two");
	two.takeDamage(3);
	three.beRepaired(5);

	return (0);
}
