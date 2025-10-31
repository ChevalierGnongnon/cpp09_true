/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BadInputException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:26:46 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 11:27:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BadInputException : public std::exception{
	private :
		const std::string	line;
		std::string			message;
		int					lineNumber;
	public :
		BadInputException(const std::string &line, int lineNumber);
		virtual const char *what() const throw();
};
