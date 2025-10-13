/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/13 13:35:52 by chhoflac         ###   ########.fr       */
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

void				RPN::makeOperation(char op){
	long long res;
	
	if (this->digits.size() >= 2){
		long long b = this->digits.top();
		this->digits.pop();
		long long a = this->digits.top();
		this->digits.pop();
		
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
		this->digits.push(res);
	}
}



long long 				RPN::evaluate(){
	std::stack<long long>	cont;
	int						i = 0;
	while (i < expression.size()){
		
		if (isOperator(this->expression[i])){
			makeOperation(this->expression[i]);
			i++;
			while (this->expression[i] && isspace(this->expression[i]))
				i++;
			continue ;
		}
		else if (this->expression[i] >= '0' && this->expression[i] <= '9'){
			if (i == this->expression.size() || (i + 1 < this->expression.size() && isspace(this->expression[i + 1]))){
				this->digits.push(static_cast<long long>(this->expression[i] - '0'));
				i++;
				while (this->expression[i] && isspace(this->expression[i]))
					i++;
				continue ;
			}
			throw (RPN::InvalidInputException());
		}
		else if (isspace(expression[i]))
			i++;
		else
			throw (RPN::InvalidInputException());
	}
	if (this->digits.size() == 0)
		throw (RPN::InvalidInputException());
	if (this->digits.size() > 1)
		throw (RPN::NoOperatorException());
	if 
		
}

const char				*RPN::DivisionByZeroException::what() const throw(){
	return ("Error : Division by 0.");
}

const char				*RPN::NoDigitsException::what() const throw(){
	return ("Error : No digits in this expression.");
}

const char				*RPN::NoOperatorException::what() const throw(){
	return ("Error : Not enough operators in this expression.");
}

const char				*RPN::TooHighDigitException::what() const throw(){
	return ("Error : digits accepted (only 0 - 9).");
}

const char				*RPN::InvalidInputException::what() const throw(){
	return ("Error : invalid input(only 0 - 9 and + - / *).");
}
