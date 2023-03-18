/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 06:29:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/18 14:05:59 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

//# include <algorithm>
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <cctype>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string s);
		~BitcoinExchange();

		void recupData(std::string file);
		void checkLine(std::string file);
		void convertRate(std::string date, float value);
		void checkValueFormat(const std::string &str, const std::string &date);

	private:
		BitcoinExchange(BitcoinExchange const &obj);
		BitcoinExchange& operator=(BitcoinExchange const &obj);

		std::map<std::string, float> _data_bitcoin;
};

#endif
