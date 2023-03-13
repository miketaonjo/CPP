/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:39:19 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/05 16:21:34 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main(void)
{
	int i[6] = {21, 2, 16, 10, 8, 19};
	double d[4] = {3.8, 9.5, 7.7, 9.7};
	char c[3] = {'!', '#', '$'};
	std::string s[2] = {"Coucou", "Bonjour"};
	
	iter(i, 6, print<int>);
	std::cout << std::endl;
	iter(d, 4, print<double>);
	std::cout << std::endl;
	iter(c, 3, print<char>);
	std::cout << std::endl;
	iter(s, 2, print<std::string>);
	std::cout << std::endl;

	iter(i, 6, doubled<int>);
	iter(d, 4, doubled<double>);
	iter(c, 3, doubled<char>);
	//iter(s, 2, doubled<std::string>);

	iter(i, 6, print<int>);
	std::cout << std::endl;
	iter(d, 4, print<double>);
	std::cout << std::endl;
	iter(c, 3, print<char>);

	return (0);
}
