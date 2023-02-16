/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:16:25 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/24 09:45:47 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(void)
{
	Harl msg;

	msg.complain("DEBUG");
	msg.complain("INFO");
	msg.complain("WARNING");
	msg.complain("ERROR");
	return (0);
}
