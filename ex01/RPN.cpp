/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/09 10:52:30 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	
}

RPN::RPN(const std::string &entry) : expression(entry){
	
}

RPN::RPN(const RPN &src){
	this->digits = src.digits;
}

RPN &RPN::operator=(const RPN &src){
	if (this != &src)
		this->digits = src.digits;
	return (*this);
}
RPN::~RPN(){
	
}

bool					RPN::isValidDigit(long long &out) const{

}

bool					RPN::pushIfDigit(const std::string &tok){
	
}


size_t					RPN::digitCount() const{
	
}

long long				RPN::makeOperation(int a, int b, char sign){
	
}
bool					RPN::isOperator(char c) const{
	
}

const char				*RPN::DivisionByZeroException::what() const throw(){
	return ("Error : Division by 0.");
}

const char				*RPN::NoDigitsException::what() const throw(){
	return ("Error : No digits in this expression.");
}

const char				*RPN::NoOperatorException::what() const throw(){
	return ("Error : No operators in this expression.");
}

const char				*RPN::TooHighDigitException::what() const throw(){
	return ("Error : digits accepted (only 0 - 9).");
}

const char				*RPN::InvalidInputException::what() const throw(){
	return ("Error : invalid input(only 0 - 9 and + - / *).");
}
