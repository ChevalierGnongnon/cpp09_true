/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/24 16:06:58 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe(){
	
}
PMergeMe::PMergeMe(const std::string &values){
	this->input = values;
	fillVector();
	fillDeque();	
}

PMergeMe::PMergeMe(const PMergeMe &src){
	this->input = src.input;
	this->vect = src.vect;
	this->cont = src.cont;
}
PMergeMe &PMergeMe::operator=(const PMergeMe &src){
	if (this != &src){
		this->input = src.input;
		this->vect = src.vect;
		this->cont = src.cont;
	}
	return (*this);
}
PMergeMe::~PMergeMe(){
	
}

int PMergeMe::getValue(size_t *i) {
	std::string strValue;
	size_t start;
	long value = 0;

	if ((*i) + 1 < this->input.size() && this->input[*i] == '+' && isdigit((unsigned char)this->input[*i + 1]))
		(*i)++;
	start = *i;
	while (*i < this->input.size() && !isspace((unsigned char)this->input[*i])) {
		if (!isdigit((unsigned char)this->input[*i]))
			throw (PMergeMe::InvalidInputException());
		(*i)++;
	}
	strValue = this->input.substr(start, *i - start);
	if (strValue == "")
		throw (PMergeMe::InvalidInputException());

	for (size_t j = 0; j < strValue.size(); j++) {
		char c = strValue[j];
		if (!isdigit((unsigned char)c))
			throw (PMergeMe::InvalidInputException());
		int digit = c - '0';
		if (value > (LONG_MAX - digit) / 10)
			throw (PMergeMe::InvalidInputException());
		value = value * 10 + digit;
	}
	if (value <= 0 || value > INT_MAX)
		throw (PMergeMe::InvalidInputException());
	return (static_cast<int>(value));
}

void				PMergeMe::fillVector(){
	size_t	i = 0;

	this->vect.clear();
	while (i < this->input.size()){
		if (isdigit((unsigned char) this->input[i])|| this->input[i] == '+'){
			this->vect.push_back(getValue(&i));
			continue ;
		}
		if (isspace((unsigned char) this->input[i])){
			i++;
			continue;
		}
		else
			throw (PMergeMe::InvalidInputException());
	}
}

void				PMergeMe::fillDeque(){
	size_t	i = 0;

	this->cont.clear();
	while (i < this->input.size()){
		if (isdigit((unsigned char) this->input[i])|| this->input[i] == '+'){
			this->cont.push_back(getValue(&i));
			continue ;
		}
		if (isspace((unsigned char) this->input[i])){
			i++;
			continue;
		}
		else
			throw (PMergeMe::InvalidInputException());
	}
}

void PMergeMe::formPairsVect(std::vector<std::pair<int, int> > &pairs, size_t limit){
	size_t								i = 0;
	int									min;
	int									max;
	
	pairs.clear();
	while (i + 1 < limit){
		if (this->vect[i] < this->vect[i + 1]){
			min = this->vect[i];
			max	= this->vect[i + 1];
		}
		else {
			max = this->vect[i];
			min	= this->vect[i + 1];
		}
		pairs.push_back(std::pair<int, int>(min, max)); //to avoid <utility> , i use constructor
		i += 2;
	}
}

void				PMergeMe::formPairsDeque(std::deque<std::pair<int, int> > &pairs, size_t limit){
	size_t								i = 0;
	int									min;
	int									max;
	
	pairs.clear();
	while (i + 1 < limit){
		if (this->cont[i] < this->cont[i + 1]){
			min = this->cont[i];
			max	= this->cont[i + 1];
		}
		else {
			max = this->cont[i];
			min	= this->cont[i + 1];
		}
		pairs.push_back(std::pair<int, int>(min, max)); //to avoid <utility> , i use constructor
		i += 2;
	}
}

double				PMergeMe::runVectorPipelineUs(){
	struct timeval	start;
	struct timeval	end;
	
	gettimeofday(&start, NULL);
	fillVector();
	sortVect();
	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec));
}

double				PMergeMe::runDequePipelineUs(){
	struct timeval	start;
	struct timeval	end;
	
	gettimeofday(&start, NULL);
	fillDeque();
	sortDeque();
	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec));
}
static void				getMaxes(const std::vector <std::pair<int, int> > &pairs, std::vector <int> &maxes){
	maxes.clear();
	maxes.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); i++){
		maxes.push_back(pairs[i].second);
	}
}
static void				getMins(const std::vector<std::pair<int, int> > &pairs, std::vector<int> mins){
	mins.clear();
	mins.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); i++){
		mins.push_back(pairs[i].first);
	}
}
void				PMergeMe::sortVect(){
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					maxes;
	std::vector<size_t>					keys;
	std::vector <int>					mins;
	size_t								i = 0;
	size_t								limit = this->vect.size();
	int									straggler;
	bool								hasStraggler = false;
	
	if (this->vect.size() % 2 == 1){
		hasStraggler = true;
		straggler = vect.back();
		limit--;
	}
	formPairsVect(pairs, limit);
	getMaxes(pairs, maxes);
	getMins(pairs, mins);
	keys.clear();
	for (size_t j = 0; j < pairs.size() - 1; j++)
		keys.push_back(i);
	
}



void				PMergeMe::sortDeque(){
	
}

