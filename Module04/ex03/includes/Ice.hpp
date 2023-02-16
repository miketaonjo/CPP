/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:19:44 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/10 15:58:26 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(std::string const &type);
		Ice(Ice const &obj);
		Ice &operator= (Ice const &obj);
		std::string const &getType() const;
		Ice *clone() const;
		void use(ICharacter &target);
};

#endif





