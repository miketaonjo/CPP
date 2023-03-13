/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:57:45 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/26 20:04:42 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, int size, void (*fct)(T&))
{
	for (int i = 0;  i < size; i++)
		fct(array[i]);
}

template<typename T>
void doubled(T &a)
{
	a *= 2;
}

template<typename T>
void print(T &s)
{
	std::cout << s << std::endl;
}

#endif
