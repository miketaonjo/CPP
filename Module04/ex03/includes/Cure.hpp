/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:40 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/10 16:03:42 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(std::string const &obj);
		Cure(Cure const &obj);
		Cure &operator= (Cure const &obj);
		std::string const &getType() const;
		Cure *clone() const;
		void use(ICharacter &target);
};

#endif
