/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/21 17:29:08 by chhoflac         ###   ########.fr       */
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

void				PMergeMe::sortVect(){
	
}
void				PMergeMe::sortDeque(){
	
}

