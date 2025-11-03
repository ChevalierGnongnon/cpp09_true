/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/11/03 11:08:59 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <ctime>
# include <iostream>
# include <vector>
# include <deque>
# include <cctype>
# include <utility>
# include <exception>
# include <string>
# include <limits.h>
# include <sys/time.h>


class PMergeMe{
	private :
		std::vector<int>		vect;
		std::vector<int>		resVector;
		std::deque<int>			cont;
		std::deque<int>			resDeque;
		std::string				input;
		
	public :
		PMergeMe();
		PMergeMe(const std::string &values);
		PMergeMe(const PMergeMe	&src);
		PMergeMe &operator=(const PMergeMe &src);
		~PMergeMe();
		
		const std::vector<int>	&getVect() const;
		const std::vector<int>	&getResVect() const;
		const std::deque<int>	&getCont() const;
		const std::deque<int>	&getResDeque() const;
		const std::string		&getInput() const;

		void					showResVector() const;
		void					showResDeque() const;
		
		int 					getValue(size_t *i);
		
		void					fillVector();
		void					fillDeque();
			
		void					formPairsVect(std::vector<std::pair<int, int> > &pairs, size_t limit);
		void					formPairsDeque(std::deque<std::pair<int, int> > &pairs, size_t limit);
				
		void					sortVect();
		void					sortDeque();

		double					runVectorPipelineUs();
		double					runDequePipelineUs();

		bool					stragglerCheckVector(size_t *limit, int *straggler);
		bool					stragglerCheckDeque(size_t *limit, int *straggler);
		
		class InvalidInputException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
};
