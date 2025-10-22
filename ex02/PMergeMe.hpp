/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/22 19:13:15 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <ctime>
# include <iostream>
# include <vector>
# include <deque>
# include <cctype>
# include <limits.h>


class PMergeMe{
	private :
		std::vector<int>	vect;
		std::deque<int>		cont;
		std::string			input;
	public :
		PMergeMe();
		PMergeMe(const std::string &values);
		PMergeMe(const PMergeMe	&src);
		PMergeMe &operator=(const PMergeMe &src);
		~PMergeMe();

		bool				checkInput();
		
		int 				getValue(size_t *i);
		
		void				fillVector();
		void				fillDeque();
		
		void				formPairs(std::vector<std::pair<int, int> > &pairs, int limit);
		
		void				sortVect();
		void				sortDeque();
		
		class NoIntsException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		
		class InvalidInputException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		
};