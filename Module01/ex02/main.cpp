/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:25:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/06 18:49:32 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string	*stringPTR = &s;
	std::string	&stringREF = s;

	std::cout << "Address s : " << &s << std::endl;
	std::cout << "Address stringPTR : " << stringPTR << std::endl;
	std::cout << "Address stringREF : " << &stringREF << std::endl;

	std::cout << "Value s : " << s << std::endl;
	std::cout << "Value stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value stringREF : " << stringREF << std::endl;
	return (0);
}
