/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 06:33:05 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/18 14:39:26 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	try
	{
		recupData("data.csv");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(std::string s)
{
	try
	{
		recupData(s);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange(void)
{
}

static bool checkLeapYear(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

static bool checkLongestMonths(int month)
{
    switch (month)
	{
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return (true);
        default:
            return (false);
    }
}

static int checkValidDate(const std::string &str)
{
	int year;
	int month;
	int day;
	char delimiter = '-';

	std::istringstream iss(str);
	if (iss >> year >> delimiter >> month >> delimiter >> day)
	{
		if (year < 2009)
			return (2);
		if (month == 2 && year >= 2009)
		{
			if (checkLeapYear(year))
			{
				if (day < 1 || day > 29)
					return (1);
			}
			if (day < 1 || day > 28)
				return (1);
		}
		else if (checkLongestMonths(month))
		{
			if (day < 1 || day > 31)
				return (1);
		}
		else
		{
			if (day < 1 || day > 30)
				return (1);
		}
		if (month > 12)
			return (1);
	}
	return (0);
}

static int checkValueType(const std::string &str)
{
    int count = 0;
	char c = '.';

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
        if (*it == c)
            ++count;
	}
    if (count == 1)
        return (count);
    else if (count > 1)
		return (count);
	return (count);
}

static bool checkValidRate(const std::string &str)
{
	float f;
	int n;

	if (checkValueType(str))
	{
		std::istringstream iss1(str);
		if (iss1 >> std::ws >> f)
		{
			if (f < 0)
				return (false);
			else if (f > std::numeric_limits<float>::max())
				return (false);
			else
				return (true);
		}
	}
	else
	{
		std::istringstream iss1(str);
		if (iss1 >> std::ws >> n)
		{
			if (n < 0)
				return (false);
			else if (n > std::numeric_limits<int>::max())
				return (false);
			else
				return (true);
		}
	}
	return (false);
}

void BitcoinExchange::recupData(std::string file)
{
	std::ifstream ifs;
	std::string line;
	std::string date;
	std::string value;
	float rate;
	char delimiter = ',';

	ifs.open(file.c_str());
	if (!ifs.is_open())
	{
		throw std::ifstream::failure("Cannot open file");
	}
	while (std::getline(ifs, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, delimiter) && std::getline(iss, value))
		{
			if (checkValidDate(date) == 0 && checkValidRate(value))
			{
				std::istringstream iss2(value);
				if (iss2 >> rate)
					_data_bitcoin[date] = rate;
			}
			else 
				continue;
		}
	}
	ifs.close();
}

static bool only_letters(const std::string &str)
{
	int i = 0;
	while (str[i])
	{
		if (!std::isalpha(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void BitcoinExchange::checkValueFormat(const std::string &str, const std::string &date)
{
	float f = 0;
	long int n = 0;
	float max = static_cast<float>(1000);

	if (checkValueType(str) == 1)
	{
		std::istringstream iss1(str);
		if (iss1 >> std::ws >> f)
		{
			if (f < 0)
			{
				std::cout << "Error: not a positive number" << std::endl;
				return ;
			}
			else if (f > max)
			{
				std::cout << "Error: too large a number" << std::endl;
				return ;
			}
			else
				convertRate(date, f);
		}
	}
	else if (checkValueType(str) == 0)
	{
		std::istringstream iss1(str);
		if (iss1 >> std::ws >> n)
		{
			if (n < 0)
			{
				std::cout << "Error: not a positive number" << std::endl;
				return ;
			}
			else if (n > 1000)
			{
				std::cout << "Error: too large a number" << std::endl;
				return ;
			}
			else
			{
				f = static_cast<float>(n);
				convertRate(date, f);
			}
		}
	}
	else
		std::cout << "Error: value not in a valid format" << std::endl;
}

static bool only_digits(std::string str)
{
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
        if (!std::isdigit(*it) && *it != '-')
            return (false);
	}
	return (true);
}


void BitcoinExchange::checkLine(std::string file)
{
	std::ifstream infile;
	std::string line = "";
	std::string date;
	std::string value;
	char delimiter = '|';

	if (this->_data_bitcoin.empty())
		throw std::logic_error ("Error: no database found");
	infile.open(file.c_str());
	if (!infile.is_open())
	{
		throw std::ifstream::failure("Cannot open file");
	}
	while (std::getline(infile, line))
	{
		int i = 0;
		std::istringstream iss(line);
		if (std::getline(iss, date, delimiter) && std::getline(iss, value))
		{
			std::istringstream iss2(date);
			if (iss2 >> date >> std::ws)
			{
				if (only_letters(date))
					continue;
				else if (checkValidDate(date) == 1 || only_digits(date) == false || date.size() != 10 || date[4] != '-' || date[7] != '-')
				{
					std::cout << "Error: invalid date format" << std::endl;
					i = 1;
				}
				else if (checkValidDate(date) == 2)
				{
					std::cout << "Error : Bitcoin was created in 2009, no valid data can exist" << std::endl;;
					i = 1;
				}
				if (!date.empty() && i == 0)
					checkValueFormat(value, date);
			}
		}
		else if (line[0] != '\0')
			std::cout << "Error: bad input => " << line << std::endl;
	}
	infile.close();
}

void BitcoinExchange::convertRate(std::string date, float value)
{
	std::map<std::string, float>::iterator it;
	std::string str;

	it = _data_bitcoin.lower_bound(date);

	float bitcoin_rate = it->second;
	if (it != _data_bitcoin.begin() && it->first != date)
	{
		--it;
		if (date.compare(date) - date.compare(it->first) < 0)
			bitcoin_rate = it->second;
	}
	float result = value * bitcoin_rate;
	if (result > std::numeric_limits<float>::max())
		std::cout << "Error: too large a number" << std::endl;
	else if (result < 0)
		std::cout << "Error: not a positive number" << std::endl;
	else
		std::cout << date << " => " << value << " = " << result << std::endl;
}
