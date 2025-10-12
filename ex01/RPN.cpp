/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/12 16:55:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	
}

RPN::RPN(const std::string &entry) : expression(entry){
	
}

RPN::RPN(const RPN &src){
	this->digits = src.digits;
	this->expression = src.expression;
}

RPN &RPN::operator=(const RPN &src){
	if (this != &src){
		this->digits = src.digits;
		this->expression = src.expression;
	}
	return (*this);
}
RPN::~RPN(){
	
}

bool					RPN::isOperator(char c){
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

long long				RPN::makeOperation(long long a, long long b, char op){
	long long res;
	switch (op){
		case '+':
			res = a + b;
			break ;
		case '-':
			res = a - b;
			break ;
		case '*':
			res = a * b;
			break ;
		case '/':
			if (b == 0)
				throw (RPN::DivisionByZeroException());
			res = a / b;	
			break ;
		default :
			throw (RPN::InvalidInputException());
	}
	return (res);
}

void					RPN::pushIfValid(int *key){
	for ()
}

long long 				RPN::evaluate(){
	std::stack<long long>	cont;
	int						i = 0;
	while (i < expression.size()){
		if (isOperator(this->expression[i]))
			pushIfValid(&i);
		else if (!isOperator(expression[i])){
			makeOperation()
		}
		else
			throw (RPN::InvalidInputException());
	}
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
