/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:06:56 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/10 05:02:08 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>

class Span
{
	public:
		Span();
		Span(std::size_t N);
		~Span();
		Span(Span const &obj);
		Span &operator=(Span const &obj);

		void addNumber(std::size_t i);
		std::size_t shortestSpan() const;
		std::size_t longestSpan() const;
		void addSeveral(std::vector<int>::iterator const &first, std::vector<int>::iterator const &last);

	private:
		std::size_t size;
		std::vector<int> array;
};

#endif
