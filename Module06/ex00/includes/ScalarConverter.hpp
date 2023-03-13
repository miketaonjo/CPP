/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:11:59 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/24 17:04:09 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <sstream>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter& operator=(ScalarConverter const &obj);
		~ScalarConverter(void);

		static std::string getType(std::string s);
		static void convert(std::string s);
		static int	precision(std::string s);
		static void printFromChar(std::string s);
		static void printFromInt(std::string s);
		static void printFromFloat(std::string s);
		static void printFromDouble(std::string s);
		static void printFromPseudo(std::string s);
};

#endif
