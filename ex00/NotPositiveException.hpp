/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotPositiveException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:17:13 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 11:17:49 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class NotPositiveException : public std::exception{
	private :
		const std::string	line;
		std::string			message;
		int					lineNumber;
	public :
		NotPositiveException(const std::string &line, int lineNumber);
		virtual const char *what() const throw();
};
