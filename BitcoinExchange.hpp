/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:45:30 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/01 15:19:33 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <fstream>
#include "Date.hpp"

class BitcoinExchange{
	private :
		std::map <Date, float>	exchangeRates;
		BitcoinExchange();
	public :
		BitcoinExchange(std::fstream &dataBase);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &src);

		std::map<Date, float>	loadData(std::fstream &file);
		float					getRate(const std::string &date) const;

		void					parseLine(const std::string &line, char sep, int lineNumber);
		Date					parseDate(const std::string &dateString);
		float					parseValue(const std::string &value);
};