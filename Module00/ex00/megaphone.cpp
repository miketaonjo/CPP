/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:35:49 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/05 15:04:14 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int	i;
	int	j;
	std::string str;

	if (argc == 1)
    {
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
	i = 1;
	while (i < argc)
	{
		j = 0;
		str = argv[i];
		while (j < (int)str.length())
		{
			str[j] = toupper(str[j]);
			j++;
		}
		std::cout << str;
		i++;
	}
	std:: cout << std::endl;
    return (0);
}
