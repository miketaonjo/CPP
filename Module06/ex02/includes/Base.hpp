/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:14:44 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/21 11:56:06 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

class Base
{
	public:
		virtual ~Base(void);
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
