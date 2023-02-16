/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:27:25 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/22 16:54:13 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		out;
	std::string		s1;
	std::string		s2;
	std::string		copy;
	std::size_t		found;
	std::size_t		diff;

	if (argc != 4)
	{
		std::cout << "Not enough argument" << std::endl;
		return (0);
	}
	s1 = argv[2];
	s2 = argv[3];
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cout << "Open failed" << std::endl;
		return (-1);
	}
	out = argv[1];
	out.append(".replace");
	ofs.open(out.c_str());
	if (ofs.fail())
	{
	 	std::cout << "Open failed" << std::endl;
		return (-1);
	}
	while (std::getline (ifs, copy))
		{
			found = copy.find(s1);
			diff = copy.find_first_not_of(s1);
			if (found != std::string::npos && diff == std::string::npos)
			{
				copy.erase(found, (int)copy.length());
				copy.insert(found, s2);
			}
			else if (found != std::string::npos && diff != std::string::npos)
			{
				copy.erase(found, diff);
				copy.insert(found, s2);
			}
			ofs << copy << std::endl;
		}
	ifs.close();
	ofs.close();
	return (0);
}
