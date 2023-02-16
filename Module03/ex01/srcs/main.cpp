/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:10:42 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/30 16:19:43 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void)
{
	ScavTrap one("One");
	ScavTrap two(one);
	ScavTrap three;

	three = two;

	one.attack("two");
	two.guardGate();

	return(0);
}
