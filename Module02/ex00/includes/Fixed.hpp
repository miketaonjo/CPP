/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:24:51 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/26 11:07:16 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP 
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed (Fixed const &obj);
		Fixed &operator=(Fixed const &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int	value;
		const static int nb_bits = 8;
};

#endif
