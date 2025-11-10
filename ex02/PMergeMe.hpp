/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:51 by chhoflac          #+#    #+#             */
/*   Updated: 2025/11/09 22:59:45 by chhoflac         ###   ########.fr       */
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
		std::vector<int>					vect;
		std::vector<int>					resVector;
		std::deque<int>						cont;
		std::deque<int>						resDeque;
		std::string							input;
		
	public :
		PMergeMe();
		PMergeMe(const std::string &values);
		PMergeMe(const PMergeMe	&src);
		PMergeMe &operator=(const PMergeMe &src);
		~PMergeMe();
		
		const std::vector<int>	&			getVect() const;
		const std::vector<int>				&getResVect() const;
		const std::deque<int>	&			getCont() const;
		const std::deque<int>				&getResDeque() const;
		const std::string					&getInput() const;

		int 								getValue(size_t *i);

		class InvalidInputException : public std::exception{
			public :
				virtual const char *what() const throw();
		};

		void								fillVector();
		void								fillDeque();

		void								showStartVector() const;
		void								showStartDeque() const;
		void								showResVector() const;
		void								showResDeque() const;
		void								ShowPairsVector(std::vector< std::pair<int, int> > &pairsVect, int i) const;
		void								ShowPairsDeque(std::deque< std::pair<int, int> > &pairsVect, int i) const;
		void								showDeque(const std::deque<int> &vect, const std::string &name);
		void								showVect(const std::vector<int> &vect, const std::string &name);

		std::vector<std::pair<int, int> >	FormPairsVector(const std::vector<int> &base, bool &hasStraggler, int &straggler);
		std::deque<std::pair<int, int> >	FormPairsDeque(const std::deque<int> &base, bool &hasStraggler, int &straggler);

		std::vector<int> 					getMaxesVector(const std::vector<std::pair<int, int> > &pairs);
		std::vector<int>					getMinsVector(const std::vector<std::pair<int, int> > &pairs);

		std::deque<int> 					getMaxesDeque(const std::deque<std::pair<int, int> > &pairs);
		std::deque<int>						getMinsDeque(const std::deque<std::pair<int, int> > &pairs);
		
		void								applyFordJohnsonOnVector(std::vector<int> &before);
		void								applyFordJohnsonOnDeque(std::deque <int> &before);

		double								runTimerOnVector();
		double								runTimerOnDeque();
};

// #include ""

		
			
		// // void					formPairsVect(std::vector<std::pair<int, int> > &pairs, size_t limit);
		// void					formPairsDeque(std::deque<std::pair<int, int> > &pairs, size_t limit);
				
		// // void					sortVect();
		// void					sortDeque();

		// // double					runVectorPipelineUs();
		// double					runDequePipelineUs();

		// // bool					stragglerCheckVector(size_t *limit, int *straggler);
		// bool					stragglerCheckDeque(size_t *limit, int *straggler);
		
		