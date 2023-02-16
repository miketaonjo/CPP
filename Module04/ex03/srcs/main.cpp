/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:28:38 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/13 19:32:14 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;
	AMateria *tmp_ice = NULL;
	AMateria *tmp_cure = NULL;

	tmp = src->createMateria("ice");
	tmp_ice = tmp;
	me->equip(tmp_ice);
	tmp = src->createMateria("cure");
	tmp_cure = tmp;
	me->equip(tmp_cure);

	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	me->use(0, *bob);
	me->use(1, *bob);

	delete tmp_ice;
	tmp_ice = NULL;
	delete tmp_cure;
	tmp_cure = NULL;
	delete bob;
	delete me;
	delete src;
	
	return (0);
}
