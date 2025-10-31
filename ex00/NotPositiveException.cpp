/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotPositiveException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:48:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 14:36:40 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NotPositiveException.hpp"
#include <sstream>

NotPositiveException::NotPositiveException(const std::string &line, int lineNumber): line(line), lineNumber(lineNumber){
	std::ostringstream oss;
	oss << "Error: Value is not positive on line : " << this->lineNumber << ": " << line;
	message = oss.str();
}

NotPositiveException::~NotPositiveException() throw(){}

const char *NotPositiveException::what() const throw(){
	return (message.c_str());
}