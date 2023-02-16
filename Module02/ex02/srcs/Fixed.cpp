/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:06:18 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/27 11:24:33 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::nb_bits = 8;

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed &Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1 < obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);

}

const Fixed &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const int n)
{
	this->value = n << this->nb_bits ;
}

Fixed::Fixed(const float nb)
{
	this->value = roundf(nb * (1 << this->nb_bits));
}

Fixed::Fixed(Fixed const &obj)
{
	*this = obj;
}

Fixed::~Fixed()
{
	return ;
}

Fixed& Fixed::operator=(Fixed const &obj)
{
	if (this != &obj)
	{
		this->value = obj.getRawBits();
	}
	return (*this);
}

bool Fixed::operator>(Fixed const &obj) const
{
	if (this->value > obj.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(Fixed const &obj) const
{
	if (this->value < obj.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed const &obj) const
{
	if (this->value >= obj.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed const &obj) const
{
	if (this->value <= obj.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(Fixed const &obj) const
{
	if (this->value == obj.value)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed const &obj) const
{
	if (this->value != obj.value)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(Fixed const &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(Fixed const &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator*(Fixed const &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(Fixed const &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed Fixed::operator++(int) //post-incrémentation
{
	Fixed tmp (*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int) //post-décrémentation
{
	Fixed tmp = this->value;
	--this->value;
	return (tmp);
}

Fixed &Fixed::operator--(void) //pré-décrémentation
{
	this->value--;
	return (*this);
}

Fixed &Fixed::operator++(void) //pré-incrémentation
{
	this->value++;
	return (*this);
}


int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->nb_bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->nb_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &obj)
{
	o << obj.toFloat();
	return (o);
}
