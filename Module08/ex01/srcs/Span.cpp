/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:22:01 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/10 06:01:02 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(void)
{
}

Span::Span(std::size_t N)
{
	this->size = 0;
	array.reserve(N);
}

Span::Span(Span const &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->size = obj.size;
		array = obj.array;
	}
	return (*this);
}

Span::~Span(void)
{
	array.clear();
}

void Span::addNumber(std::size_t i)
{
	if (this->array.capacity() >= this->size)
	{
		array.push_back(i);
		this->size++;
	}
	else
	{
		throw std::length_error("Over the array range");
	}
}

std::size_t Span::shortestSpan() const
{
	if (array.size() < 2)
		throw std::logic_error("Less than 2 numbers in the array");
	std::size_t shortest = 0;
	std::vector<int> span;

	for (int i = 0; i < static_cast<int>(array.size()); i++)
	{
		for (int j = 0; j < static_cast<int>(array.size()); j++)
		{
			if (array[i] - array[j] > 0)
			{
				shortest = array[i] - array[j];
				span.push_back(shortest);
			}
		}
	}
	shortest = *(std::min_element(span.begin(), span.end()));
	return (shortest);
}

std::size_t Span::longestSpan() const
{
	if (array.size() < 2)
		throw std::logic_error("Less than 2 numbers in the array");
	std::size_t longest = 0;
	longest = *(std::max_element(array.begin(), array.end())) - *(std::min_element(array.begin(), array.end()));
	return (longest);
}

void Span::addSeveral(std::vector<int>::iterator const &first, std::vector<int>::iterator const &last)
{
	if (this->size + std::distance(first, last) <= array.capacity())
		array.insert(array.end(), first, last);
	else
		throw std::length_error("Over the array range");
}
