/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BadInputException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:31:29 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 14:36:27 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BadInputException.hpp"
#include <sstream>

BadInputException::BadInputException(const std::string &line, int lineNumber): line(line), lineNumber(lineNumber){
	std::ostringstream oss;
	oss << "Error: bad input on line : " << this->lineNumber << ": " << line;
	message = oss.str();
}

BadInputException::~BadInputException() throw(){}


const char *BadInputException::what() const throw(){
	return (message.c_str());
}