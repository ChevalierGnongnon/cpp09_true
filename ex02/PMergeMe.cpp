/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/20 16:25:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe(){
	
}
PMergeMe::PMergeMe(const std::string &values){
	this->input = values;
	if (this->checkInput()){
		fillVector();
		fillDeque();	
	}
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

bool				PMergeMe::checkInput(){
	for (int i = 0; i < this->input.size(); i++){
		if (!isspace(this->input[i]) && (this->input[i] <= '0' || this->input[i] >= '9'))
			throw (PMergeMe::InvalidInputException());
	}
}

int 				PMergeMe::getValue(size_t *i){
	std::string	strValue;
	size_t		start = (*i);
	int			value;
	
	while ((*i) < this->input.size() && !isspace(this->input[(*i)]))
		(*i)++;
	strValue = this->input.substr(start, (*i));
	if (strValue == "")
		throw (PMergeMe::InvalidInputException());
	value = std::atoi(strValue.c_str());
	return (value);
}

void				PMergeMe::fillVector(){
	
}

void				PMergeMe::fillDeque(){
	
}

void				PMergeMe::sortVect(){
	
}
void				PMergeMe::sortDeque(){
	
}

