/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/15 14:59:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <ctime>
# include <iostream>
# include <vector>
# include <deque>

class PMergeMe{
	private :
		std::vector<int>	vect;
		std::deque<int>		cont;
		std::string	input;
	public :
		PMergeMe();
		PMergeMe(const std::string &input);
		PMergeMe(const PMergeMe	&src);
		PMergeMe &operator=(const PMergeMe &src);
		~PMergeMe();

		void				checkInput();
		
		void				fillVector();
		void				fillDeque();
		
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