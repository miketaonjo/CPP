/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:11:24 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/22 16:30:16 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl msg;
	if (argc != 2)
	{
		std::cerr << "Need one level as parameter (DEBUG, INFO, WARNING, ERROR)" << std::endl;
		return (1);
	}
	msg.complain(argv[1]);
	return (0);
}
