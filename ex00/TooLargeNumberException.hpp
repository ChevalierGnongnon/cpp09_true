/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TooLargeNumberException.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:15:57 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 14:36:59 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "BitcoinExchange.hpp"

class TooLargeNumberException : public std::exception{
	private :
		const std::string	line;
		std::string			message;
		int					lineNumber;
	public :
		TooLargeNumberException(const std::string &line, int lineNumber);
		virtual ~TooLargeNumberException() throw();
		virtual const char *what() const throw();
};