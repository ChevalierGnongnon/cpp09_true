/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:45:30 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/05 14:47:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Date.hpp"

class BitcoinExchange{
	private :
		std::map <Date, float>	dataCSV;
		std::map <Date, float>	valuesCSV;
		BitcoinExchange();
	public :
		BitcoinExchange(std::fstream &dataFile, std::fstream &valueFile);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &src);

		void			loadData(std::map<Date, float> &target, std::fstream &file, char sep);
		float			getRate(const Date &date) const;

		int 			sepCheck(const std::string &line, char sep);
		bool 			checkIsNum(const std::string &value);
		bool 			checkIsValidFloat(const std::string &value);
		std::string		cutSpaces(const std::string &tmp);
		
		void			errorBadInput(const std::string &line, int lineNumber);
		void			errorNotPositive(const std::string &line, int lineNumber);
		void			errorTooLargeNumber(const std::string &line, int lineNumber);

		Date 			parseDate(const std::string &line);
		void			parseLine(std::map<Date, float> &target, const std::string &line, char sep, int lineNumber);
		float			parseValue(const std::string &valueString);
};