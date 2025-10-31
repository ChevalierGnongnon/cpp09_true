/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TooLargeNumberException.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:50:19 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 11:59:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "TooLargeNumberException.hpp"

TooLargeNumberException::TooLargeNumberException(const std::string &line, int lineNumber): line(line), lineNumber(lineNumber){
	std::ostringstream oss;
	oss << "Error: Value is too large on line : " << lineNumber << ": " << line;
	message = oss.str();
}
const char *TooLargeNumberException::what() const throw(){
	return (message.c_str());
}