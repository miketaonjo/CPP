/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:10:42 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/30 16:50:07 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap one("One");
	FragTrap two(one);
	FragTrap three;

	three = two;

	one.attack("two");
	two.highFivesGuys();

	return(0);
}
