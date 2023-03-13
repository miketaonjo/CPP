/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:52:58 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/25 16:56:04 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

std::string ScalarConverter::getType(std::string s)
{
	const char *str = s.c_str();
	std::string ret;

	std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int i = -1;

	for (int j = 0; j < 6; j++)
	{
		if (pseudo[j] == s)
		{
			i = j;
			break;
		}
	}
	switch (i)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			ret = "pseudo";
			return (ret);
		default:
			ret = "Undefined";
	}
	if (str[1] == '\0' && ((str[0] >= 33 && str[0] <= 47) || (str[0] >= 58 && str[0] <= 126)))
	{
		ret = "char";
		return (ret);
	}
	else if (str[0] == '.' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
	{
		int i = 0;
		if (str[1] == '-')
			return (ret);
		while((str[i] >= '0' && str[i] <= '9') || str[i] == 'f' || str[i] == '-' || str[i] == '.')
		{
			if (str[i] == '.')
			{
				i++;
				if (str[i - 2] == 'f')
					return (ret);
				while (i > 0 && (str[i] >= '0' && str[i] <= '9') && str[i] != 'f')
					i++;
								if ((str[i - 2] >= '0' && str[i - 2] <= '9' && str[i] == 'f' && str[i + 1] == '\0')
					|| (str[i - 1] >= '0' && str[i - 1] <= '9' && str[i] == 'f' && str[i + 1] == '\0'))
				{
					ret = "float";
					return (ret);
				}
				else if (str[i] != 'f')
				{
					while (str[i] >= '0' && str[i] <= '9')
						i++;
					if (str[i] == '\0')
					{
						ret = "double";
						return (ret);
					}
				}
				else
					return (ret);
			}
			else if ((int)s.length() < 12)
			{
				int len = 0;
				if (str[0] == '-')
				{
					for (int i = 1; std::isdigit(str[i]); i++)
						len++;
					if (len == (int)s.length() - 1)
					{
						long test = atol(str);
						if (test >= -2147483648 && test <= 2147483647)
						{
							ret = "int";
							return (ret);
						}
					}
				}
				else
				{
					for (int i = 0; std::isdigit(str[i]); i++)
						len++;
					if (len == (int)s.length())
					{
						long test = atol(str);
						if (test >= -2147483648 && test <= 2147483647)
						{
							ret = "int";
							return (ret);
						}
					}
				}
			}
			i++;
		}
	}
	return (ret);
}

void ScalarConverter::convert(std::string s)
{
	std::string type = ScalarConverter::getType(s);
	std::string types[5] = {"char", "int", "float", "double", "pseudo"};
	int i = -1;
	for (int j = 0; j < 5; j++)
	{
		if (types[j] == type)
		{
			i = j;
			break;
		}
	}
	switch (i)
	{
		case 0:
			ScalarConverter::printFromChar(s);
			break;
		case 1:
			ScalarConverter::printFromInt(s);
			break;
		case 2:
			ScalarConverter::printFromFloat(s);
			break;
		case 3:
			ScalarConverter::printFromDouble(s);
			break;
		case 4:
			ScalarConverter::printFromPseudo(s);
			break;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}

void ScalarConverter::printFromChar(std::string s)
{
	const char *str = s.c_str();
	std::cout << "char: " << s << std::endl;

	if (str[0] >= 32 && str[0] <= 126)
	{
		int i = static_cast<int>(str[0]);
		std::cout << "int: " << i << std::endl;
		float j = static_cast<float>(str[0]);
		std::cout << std::fixed << std::setprecision(1) << "float: " << j << "f" << std::endl;
		double k = static_cast<double>(str[0]);
		std::cout << std::fixed << std::setprecision(1) << "double: " << k << std::endl;
	}
}

void ScalarConverter::printFromInt(std::string s)
{
	std::stringstream ss;
	int i = 0;
	ss << s;
	ss >> i;
	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(i);
		std::cout << "char: " << c << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(i);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	double d = static_cast<double>(i);
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

int ScalarConverter::precision(std::string s)
{
	int len = 0;
	const char *str = s.c_str();

	while (*str != '.')
		str++;
	if (str[0] == '.' && str[1] == '\0')
		len += 2;
	else if(str[1] == 'f' && str[2] == '\0')
		len += 3;
	else if (*str == '.')
	{
		while (*str)
		{
			str++;
			len++;
		}
	}
	return (len - 1);
}

void ScalarConverter::printFromFloat(std::string s)
{
	const char *str = s.c_str();
	int len = ScalarConverter::precision(s);
	float i = strtof(str, NULL);
	int j = static_cast<int>(i);
	char c = static_cast<char>(j);

	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (i >= -2147483648.0 && i <= 2147483647.0)
		std::cout << "int: " << j << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(len - 1) << "float: " << i << "f" << std::endl;
	double d = static_cast<double>(i);
	std::cout << std::fixed << std::setprecision(len - 1) << "double: " << d << std::endl;
}

void ScalarConverter::printFromDouble(std::string s)
{
	const char *str = s.c_str();
	double i = strtod(str, NULL);
	int j = static_cast<int>(i);
	float f = static_cast<float>(i);
	char c = static_cast<char>(j);
	int len = ScalarConverter::precision(s);

	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (i >= -2147483648.0 && i <= 2147483647.0)
		std::cout << "int: " << j << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(len) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(len) << "double: " << i << std::endl;
}

void ScalarConverter::printFromPseudo(std::string s)
{
	const char *str = s.c_str();
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if ((std::strcmp(str, "-inf") == 0)
		|| (std::strcmp(str, "+inf") == 0)
		|| (std::strcmp(str, "nan") == 0))
	{
		double i = strtod(str, NULL);
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << i << std::endl;
	}
	else
	{
		float i = strtof(str, NULL);
		std::cout << "float: " << i << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
}
