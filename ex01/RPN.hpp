/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:54 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 15:26:51 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <cctype>
#include <exception>
#include <string>

class RPN{
	private :
		std::string				expression;
		std::stack<long long>	digits;
		static bool				isOperator(char c);
	public :
		RPN();
		RPN(const std::string &entry);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void					makeOperation(char op);
		long long				evaluate();
		
		class DivisionByZeroException : public std::exception{
			public :
				virtual ~DivisionByZeroException() throw() {};
				virtual const char *what() const throw();
		};
		
		class NoDigitsException : public std::exception{
			public :
				virtual ~NoDigitsException() throw() {};
				virtual const char *what() const throw();
		};
		
		class NoOperatorException : public std::exception{
			public :
				virtual ~NoOperatorException() throw() {};
				virtual const char *what() const throw();
		};
		class TooHighDigitException : public std::exception{
			public :
				virtual ~TooHighDigitException() throw() {};
				virtual const char *what() const throw();
		};
		class InvalidInputException : public std::exception{
			public :
				virtual ~InvalidInputException() throw() {}
				virtual const char *what() const throw();
		};
};