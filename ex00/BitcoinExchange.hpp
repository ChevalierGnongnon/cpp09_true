/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:45:30 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 11:12:41 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iomanip>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <sstream>
#include "Date.hpp"

class BitcoinExchange{
	private :
		std::multimap <Date, float>	dataCSV;
		std::multimap <Date, float>	valuesCSV;
		BitcoinExchange();
	public :
		BitcoinExchange(std::fstream &dataFile, std::fstream &valueFile);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &src);

		void			loadData(std::multimap<Date, float> &target, std::fstream &file, char sep);
		float			getRate(const Date &date) const;

		int 			sepCheck(const std::string &line, char sep);
		bool 			checkIsNum(const std::string &value);
		bool 			checkIsValidFloat(const std::string &value);
		std::string		cutSpaces(const std::string &tmp);

		
		class BadInputException : public std::exception{
			private :
				const std::string	line;
				std::string			message;
				int					lineNumber;
			public :
				BadInputException(const std::string &line, int lineNumber);
				virtual const char *what() const throw();
		};
		
		class NotPositiveException : public std::exception{
			private :
				const std::string	line;
				std::string			message;
				int					lineNumber;
			public :
				NotPositiveException(const std::string &line, int lineNumber);
				virtual const char *what() const throw();
		};

		class TooLargeNumberException : public std::exception{
			private :
				const std::string	line;
				std::string			message;
				int					lineNumber;
			public :
				TooLargeNumberException(const std::string &line, int lineNumber);
				virtual const char *what() const throw();
		};

		Date 			parseDate(const std::string &line);
		void			parseLine(std::multimap<Date, float> &target, const std::string &line, char sep, int lineNumber);
		float			parseValue(const std::string &valueString);

		void			evaluate() const;
};