/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:54 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/08 15:15:49 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <exception>
#include <string>

class RPN{
	private :
		std::string				expression;
		std::stack<long long>	digits;
		static long long		makeOperation(long long a, long long b, char sign);
		static bool				isOperator(char c);
	public :
		RPN();
		RPN(const std::string &entry);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		bool					isValidDigit(const std::string &entry, long long &out) const;
		bool					isValidEntry(const std::string &entry);
		bool					pushIfDigit(const std::string &tok);
		size_t					digitCount() const;

		
		
		long long				evaluate();
		
		class DivisionByZeroException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		
		class NoDigitsException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		
		class NoOperatorException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		class TooHighDigitException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		class InvalidInputException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
};