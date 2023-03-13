/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:04:32 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/06 16:21:55 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &obj);
		Array& operator=(Array const &obj);
		~Array(void);
		unsigned int size(void) const;
		T &operator[] (unsigned int i) const;

	private:
		unsigned int len;
		T *array;
};

# include "Array.tpp"

#endif
