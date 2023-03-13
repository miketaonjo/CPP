/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:43:34 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/05 16:15:49 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(T const &a, T const &b)
{
	if (a > b || a == b)
		return (b);
	else
		return (a);
}

template<typename T>
T max(T const &a, T const &b)
{
	if (b > a || a == b)
		return (b);
	else
		return (a);
}

#endif
