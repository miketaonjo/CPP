/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:49:59 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/27 10:34:52 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP 
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float nb);
		~Fixed(void);
		Fixed (Fixed const &obj);

		Fixed &operator=(Fixed const &obj);
		
		Fixed operator+(Fixed const &obj) const;
		Fixed operator-(Fixed const &obj) const;
		Fixed operator*(Fixed const &obj) const;
		Fixed operator/(Fixed const &obj) const;
		
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed &operator++(void);
		Fixed &operator--(void);

		bool operator>(Fixed const &obj) const;
		bool operator<(Fixed const &obj) const;
		bool operator>=(Fixed const &obj) const;
		bool operator<=(Fixed const &obj) const;
		bool operator==(Fixed const &obj) const;
		bool operator!=(Fixed const &obj) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		const static Fixed &min(Fixed const &obj1, Fixed const &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		const static Fixed &max(Fixed const &obj1, Fixed const &obj2);

	private:
		int	value;
		const static int nb_bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &obj);

#endif
