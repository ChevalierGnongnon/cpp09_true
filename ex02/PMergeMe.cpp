/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/21 14:50:51 by chhoflac         ###   ########.fr       */
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
	else
		throw (PMergeMe::InvalidInputException());
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
	int n = 0;
	
	for (int i = 0; i < this->input.size(); i++){
		if (!isspace(this->input[i]) && (this->input[i] <= '0' || this->input[i] >= '9'))
			return (false);
		else
			n++;
	}
	if (n == 0)
		return (false);
	return (true);
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
	size_t	i = 0;
	size_t	j = 0;
	
	while (i < this->input.size()){
		if (this->input[i] >= '0' && this->input[i] <= '9'){
			this->vect[j] = getValue(&i);
			j++;
			continue ;
		}
		i++;
	}
}

void				PMergeMe::fillDeque(){
	
}

void				PMergeMe::sortVect(){
	
}
void				PMergeMe::sortDeque(){
	
}

