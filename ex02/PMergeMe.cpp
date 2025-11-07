/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/11/07 15:13:23 by chhoflac         ###   ########.fr       */
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

void					PMergeMe::showStartVector() const{
	for (size_t i = 0; i < this->resVector.size(); i++){
		std::cout << "[" << this->vect[i] << "]";
		if (i + 1 < this->resVector.size())
			std::cout << " ";
	}
}
void					PMergeMe::showStartDeque() const{
	for (size_t i = 0; i < this->resDeque.size(); i++){
		std::cout << "[" << this->cont[i] << "]";
		if (i + 1 < this->resDeque.size())
			std::cout << " ";
	}
}

void					PMergeMe::showResVector() const{
	for (size_t i = 0; i < this->resVector.size(); i++){
		std::cout << resVector[i];
		if (i + 1 < this->resVector.size())
			std::cout << " ";
	}
}
void					PMergeMe::showResDeque() const{
	for (size_t i = 0; i < this->resDeque.size(); i++){
		std::cout << resDeque[i];
		if (i + 1 < this->resDeque.size())
			std::cout << " ";
	}
}

const std::vector<int>		&PMergeMe::getVect() const{
	return (this->vect);
}
const std::vector<int>		&PMergeMe::getResVect() const{
	return (this->resVector);
}
const std::deque<int>		&PMergeMe::getCont() const{
	return (this->cont);
}
const std::deque<int>		&PMergeMe::getResDeque()const{
	return (this->resDeque);
}
const std::string			&PMergeMe::getInput()const{
	return (this->input);
}

const char* PMergeMe::InvalidInputException::what() const throw() {
    return ("Error");
}

int 			PMergeMe::getValue(size_t *i) {
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

void			PMergeMe::fillVector(){
	size_t i = 0;
	
	this->vect.clear();
	while(i < this->input.size()){
		if (isdigit(this->input[i]) || this->input[i] == '+')
			this->vect.push_back(getValue(&i));
		else if (isspace(this->input[i])){
			while (i < this->input.size() && isspace(this->input[i]))
				i++;
		}
		else
			throw (PMergeMe::InvalidInputException());
	}
}

void			PMergeMe::fillDeque(){
	size_t i = 0;
	
	this->cont.clear();
	while(i < this->input.size()){
		if (isdigit(this->input[i]) || this->input[i] == '+')
			this->cont.push_back(getValue(&i));
		else if (isspace(this->input[i])){
			while (i < this->input.size() && isspace(this->input[i]))
				i++;
		}
		else
			throw (PMergeMe::InvalidInputException());
	}
}

















// // void				PMergeMe::fillVector(){
// // 	size_t	i = 0;

// // 	this->vect.clear();
// // 	while (i < this->input.size()){
// // 		if (isdigit((unsigned char) this->input[i])|| this->input[i] == '+'){
// // 			this->vect.push_back(getValue(&i));
// // 			continue ;
// // 		}
// // 		if (isspace((unsigned char) this->input[i])){
// // 			i++;
// // 			continue;
// // 		}
// // 		else
// // 			throw (PMergeMe::InvalidInputException());
// // 	}
// // }



// // void 				PMergeMe::formPairsVect(std::vector<std::pair<int, int> > &pairs, size_t limit){
// // 	size_t	i = 0;
// // 	int		min;
// // 	int		max;
	
	
// // 	pairs.clear();
// // 	while (i + 1 < limit){
// // 		if (this->vect[i] < this->vect[i + 1]){
// // 			min = this->vect[i];
// // 			max	= this->vect[i + 1];
// // 		}
// // 		else {
// // 			max = this->vect[i];
// // 			min	= this->vect[i + 1];
// // 		}
// // 		pairs.push_back(std::pair<int, int>(min, max)); //to avoid <utility> , i use constructor
// // 		i += 2;
// // 	}
// // }



// // double				PMergeMe::runVectorPipelineUs(){
// // 	struct timeval	start;
// // 	struct timeval	end;
	
// // 	gettimeofday(&start, NULL);
// // 	fillVector();
// // 	sortVect();
// // 	gettimeofday(&end, NULL);
// // 	return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec));
// // }


// // static void			getMaxesVector(const std::vector <std::pair<int, int> > &pairs, std::vector <int> &maxes){
// // 	maxes.clear();
// // 	maxes.reserve(pairs.size());
// // 	for (size_t i = 0; i < pairs.size(); i++){
// // 		maxes.push_back(pairs[i].second);
// // 	}
// // }
// // static void			getMinsVector(const std::vector<std::pair<int, int> > &pairs, std::vector<int> &mins){
// // 	mins.clear();
// // 	mins.reserve(pairs.size());
// // 	for (size_t i = 0; i < pairs.size(); i++){
// // 		mins.push_back(pairs[i].first);
// // 	}
// // }

// // static void			insertionSortVector(std::vector<int> &base, std::vector<size_t> &keys){
// // 	size_t	i = 1;
// // 	size_t	j;
// // 	size_t	key;
// // 	int		val;
	
// // 	if (base.empty() || keys.size() != base.size())
// //    		return;
// // 	for (; i < base.size(); ++i){
// // 		val = base[i];
// // 		key = keys[i];
// // 		j = i;
// // 		while (j > 0 && base[j - 1] > val){
// // 			base[j] = base[j - 1];
// // 			keys[j] = keys[j - 1];
// // 			--j;
// // 		}
// // 		base[j] = val;
// // 		keys[j] = key;
// // 	}
// // }

// // std::vector<size_t>	makeJacobsthalVector(size_t size){
// // 	std::vector<size_t>	j;
// // 	size_t				next;

// // 	j.push_back(0);
// // 	j.push_back(1);
// // 	if (size <= 1)
// // 		return (j);
// // 	while (true){
// // 		next = j[j.size() - 1] + (2 * j[j.size() - 2]);
// // 		j.push_back(next);
// // 		// std::cout << "next :" << next << std::endl; if we want to see jacobsthal value
// // 		if (next >= size)
// // 			break;
// // 	}
// // 	return (j);
// // }

// // static size_t 		lower_bound_upto_vector(const std::vector<int> &vect, size_t lo, size_t hi, int v){
// // 	size_t	mid;
	
// // 	while (lo < hi){
// // 		mid = lo + (hi -lo) / 2;
// // 		if (vect[mid] < v)
// // 			lo = mid + 1;
// // 		else
// // 			hi = mid;
// // 	}	
// // 	return (lo);
// // }

// // void				insertMinsByJacobsthalOrderVector(std::vector<int> &result, std::vector<size_t> &order, std::vector<int> &mins, std::vector<size_t> &pos){
// // 	size_t	pidx;
// // 	size_t	hi;
// // 	size_t	ins;
// // 	int		val;

// // 	for (size_t oi = 0; oi < order.size(); ++oi){
// // 		pidx = order[oi];
// // 		val  = mins[pidx];
// // 		hi   = pos[pidx];
// // 		ins  = lower_bound_upto_vector(result, 0, hi, val);
// // 		result.insert(result.begin() + ins, val);
// // 		for (size_t k = 0; k < pos.size(); ++k) {
// // 			if (pos[k] >= ins)
// // 				pos[k]++;
// //     	}
// // 	}
// // }
// // void 				placeStragglerVector(std::vector<int> &result, int straggler){
// // 	result.insert(result.begin() + lower_bound_upto_vector(result, 0, result.size(), straggler), straggler);
// // }

// // void				buildJacobsthalInsertionOrderVector(std::vector<size_t>	&order, const std::vector<size_t> &jackobstahl, size_t pairsSize){
// // 	size_t	l;
// // 	size_t	r;
// // 	long	index;

// // 	if (pairsSize == 0)
// // 		return ;
// // 	for (size_t m = 2; m < jackobstahl.size(); ++m){
// // 		l = jackobstahl[m - 1];
// // 		r = jackobstahl[m] - 1;
// // 		if (l >= pairsSize)
// // 			break ;
// // 		if (r >= pairsSize)
// // 			r = pairsSize - 1;
// // 		for (index = static_cast<long>(r); index >= static_cast<long>(l); --index){
// // 			if (index == 0)
// // 				continue ;
// // 			order.push_back(static_cast<size_t>(index));
// // 		}
// // 	}
// // }

// // bool				PMergeMe::stragglerCheckVector(size_t *limit, int *straggler){
// // 	if (this->vect.size() % 2 == 1){
// // 		(*straggler) = vect.back();
// // 		(*limit)--;
// // 		return (true);
// // 	}
// // 	return (false);
// // }

// // void				PMergeMe::sortVect(){
// // 	std::vector<std::pair<int, int> >	pairs;
// // 	std::vector<int>					result;
// // 	std::vector<int>					maxes;
// // 	std::vector<size_t>					keys;
// // 	std::vector <int>					mins;
// // 	std::vector<size_t>					jackobstahl;
// // 	size_t								limit = this->vect.size();
// // 	size_t								pairsSize;
// // 	std::vector<size_t>					pos;
// // 	std::vector<size_t>					order;
// // 	int									straggler;
// // 	bool								hasStraggler = false;
	
// // 	hasStraggler = this->stragglerCheckVector(&limit, &straggler);
// // 	formPairsVect(pairs, limit);
// // 	getMaxesVector(pairs, maxes);
// // 	getMinsVector(pairs, mins);
// // 	keys.clear();
// // 	for (size_t j = 0; j < pairs.size(); j++)
// // 		keys.push_back(j);
// // 	insertionSortVector(maxes, keys);
// // 	pairsSize = keys.size();
// // 	if (keys.size() == 0 && hasStraggler){
// // 		result.push_back(straggler);
// // 		this->resVector = result;
// // 		return ;
// // 	}
// // 	else if (keys.size() == 0 && !hasStraggler)
// // 		return ;
// // 	result = maxes;
// // 	jackobstahl = makeJacobsthalVector(pairsSize);
// // 	pos.resize(keys.size());
// // 	for (size_t k = 0; k < keys.size(); k++){
// // 		size_t p = keys[k];
// // 		pos[p] = k;
// // 	}
// // 	if (pairsSize > 0)
// // 		order.push_back(0);
// // 	buildJacobsthalInsertionOrderVector(order, jackobstahl, pairsSize);
// // 	insertMinsByJacobsthalOrderVector(result, order, mins, pos);
// // 	if (hasStraggler)
// // 		placeStragglerVector(result, straggler);
// // 	this->resVector = result;
// // }

// //////////////////////////////////////////////////
// //////////////////////DEQUE///////////////////////
// //////////////////////////////////////////////////

// //forms pairs and place it into a vector of <std::pair<int, int>>. changes position if min is on the right.
// void				PMergeMe::formPairsDeque(std::deque<std::pair<int, int> > &pairs, size_t limit){
// 	size_t	i = 0;
// 	int		min;
// 	int		max;
	
// 	pairs.clear();
// 	while (i + 1 < limit){
// 		if (this->cont[i] < this->cont[i + 1]){
// 			min = this->cont[i];
// 			max	= this->cont[i + 1];
// 		}
// 		else {
// 			max = this->cont[i];
// 			min	= this->cont[i + 1];
// 		}
// 		pairs.push_back(std::pair<int, int>(min, max)); //to avoid <utility> , i use constructor
// 		i += 2;
// 	}
// }

// //Starts chrono and make algo
// double				PMergeMe::runDequePipelineUs(){
// 	struct timeval	start;
// 	struct timeval	end;
	
// 	gettimeofday(&start, NULL);
// 	fillDeque();
// 	sortDeque();
// 	gettimeofday(&end, NULL);
// 	return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec));
// }


// //Fills the deque container
// void				PMergeMe::fillDeque(){
// 	size_t	i = 0;

// 	this->cont.clear();
// 	while (i < this->input.size()){
// 		if (isdigit((unsigned char) this->input[i])|| this->input[i] == '+'){
// 			this->cont.push_back(getValue(&i));
// 			continue ;
// 		}
// 		if (isspace((unsigned char) this->input[i])){
// 			i++;
// 			continue;
// 		}
// 		else
// 			throw (PMergeMe::InvalidInputException());
// 	}
// }

// //gets the first element of each pair and place into a container (mins)
// void				getMinsDeque(const std::deque<std::pair<int, int> > &pairs, std::deque<int> &mins){
// 	mins.clear();
// 	for (size_t i = 0; i < pairs.size(); i++)
// 		mins.push_back(pairs[i].first);
// }

// //gets the second element of each pair and place into a container (maxes)
// void				getMaxesDeque(const std::deque<std::pair<int, int> > &pairs, std::deque<int> &maxes){
// 	maxes.clear();
// 	for (size_t i = 0; i < pairs.size(); i++)
// 		maxes.push_back(pairs[i].second);
// }

// //Sorts maxes by insertion algorithm. change the keys deque too to keep the order.
// static void			insertionSortDeque(std::deque<int> &base, std::deque<size_t> &keys){
// 	size_t	i = 1;
// 	size_t	j;
// 	size_t	key;
// 	int		val;
	
// 	if (base.empty() || keys.size() != base.size())
//    		return;
// 	for (; i < base.size(); ++i){
// 		val = base[i];
// 		key = keys[i];
// 		j = i;
// 		while (j > 0 && base[j - 1] > val){
// 			base[j] = base[j - 1];
// 			keys[j] = keys[j - 1];
// 			--j;
// 		}
// 		base[j] = val;
// 		keys[j] = key;
// 	}
// }

// //makes jacobsthal suite, it's also possible to do it without recursion.
// //while (true) here because we have to calculate next before testing it.
// //Jackobsthal suite : j(n) = j(n - 1) + (2 * j(n - 2))
// // J(0) = 0
// // J(1) = 1
// // J(2) = J(1) + 2 * J(0) = 1 + 2 * 0 = 1
// // J(3) = J(2) + 2 * J(1) = 1 + 2 * 1 = 3
// // J(4) = J(3) + 2 * J(2) = 3 + 2 * 1 = 5
// // J(5) = J(4) + 2 * J(3) = 5 + 2 * 3 = 11
// std::deque<size_t>	makeJacobsthalDeque(size_t size){
// 	std::deque<size_t>	j;
// 	size_t				next;

// 	j.push_back(0);
// 	j.push_back(1);
// 	if (size <= 1)
// 		return (j);
// 	while (true){ 
// 		next = j[j.size() - 1] + (2 * j[j.size() - 2]);
// 		j.push_back(next);
// 		if (next >= size)
// 			break;
// 	}
// 	return (j);
// }

// static size_t		lower_bound_upto_deque(const std::deque<int> &vect, size_t lo, size_t hi, int v){
// 	size_t mid;
	
// 	while (lo < hi){
// 		mid = lo + (hi -lo) / 2;
// 		if (vect[mid] < v)
// 			lo = mid + 1;
// 		else
// 			hi = mid;
// 	}	
// 	return (lo);
// }

// void				insertMinsByJacobsthalOrderDeque(std::deque<int> &result, std::deque<size_t> &order, std::deque<int> &mins, std::deque<size_t> &pos){
// 	size_t	pidx;
// 	size_t	hi;
// 	size_t	ins;
// 	int		val;

// 	for (size_t oi = 0; oi < order.size(); ++oi){
// 		pidx = order[oi];
// 		val  = mins[pidx];
// 		hi   = pos[pidx];
// 		ins  = lower_bound_upto_deque(result, 0, hi, val);
// 		result.insert(result.begin() + ins, val);
// 		for (size_t k = 0; k < pos.size(); ++k) {
// 			if (pos[k] >= ins)
// 				pos[k]++;
//     	}
// 	}
// }

// void				buildJacobsthalInsertionOrderDeque(std::deque<size_t>	&order, const std::deque<size_t> &jackobstahl, size_t pairsSize){
// 	size_t	l;
// 	size_t	r;
// 	long	index;

// 	if (pairsSize == 0)
// 		return ;
// 	for (size_t m = 2; m < jackobstahl.size(); ++m){
// 		l = jackobstahl[m - 1];
// 		r = jackobstahl[m] - 1;
// 		if (l >= pairsSize)
// 			break ;
// 		if (r >= pairsSize)
// 			r = pairsSize - 1;
// 		for (index = static_cast<long>(r); index >= static_cast<long>(l); --index){
// 			if (index == 0)
// 				continue ;
// 			order.push_back(static_cast<size_t>(index));
// 		}
// 	}
// }

// //checks if the container size is odd. if yes, isolate the last element.
// bool				PMergeMe::stragglerCheckDeque(size_t *limit, int *straggler){
// 	if (this->cont.size() % 2 == 1){
// 		(*straggler) = cont.back();
// 		(*limit)--;
// 		return (true);
// 	}
// 	return (false);
// }

// void 				placeStragglerDeque(std::deque<int> &result, int straggler){
// 	result.insert(result.begin() + lower_bound_upto_deque(result, 0, result.size(), straggler), straggler);
// }


// void				PMergeMe::sortDeque(){
// 	std::deque<std::pair<int, int> >	pairs;
// 	std::deque<int>						result;
// 	std::deque<int>						maxes;
// 	std::deque<size_t>					keys;
// 	std::deque <int>					mins;
// 	std::deque<size_t>					jackobstahl;
// 	size_t								limit = this->cont.size();
// 	size_t								pairsSize;
// 	std::deque<size_t>					pos;
// 	std::deque<size_t>					order;
// 	int									straggler;
// 	bool								hasStraggler = false;
	
// 	hasStraggler = this->stragglerCheckDeque(&limit, &straggler);
// 	formPairsDeque(pairs, limit); // form pairs to separate min amd max later.
// 	getMaxesDeque(pairs, maxes); // put maxes value (second) into another deque.
// 	getMinsDeque(pairs, mins); // put mins value (first) into another deque.
// 	keys.clear(); //clear keys to avoid residual values (prevention, normally wont happen)
// 	for (size_t j = 0; j < pairs.size(); j++)
// 		keys.push_back(j); //push keys for keeping the order
// 	insertionSortDeque(maxes, keys); //sort maxes
// 	pairsSize = keys.size(); // get pair numbers for jackobsthal suite
// 	if (keys.size() == 0 && hasStraggler){ // if there is only one number, just push (the straggler) it and early return.
// 		result.push_back(straggler);
// 		this->resDeque = result;
// 		return ;
// 	}
// 	else if (keys.size() == 0 && !hasStraggler) // if theres nothing, just early return.
// 		return ;
// 	result = maxes; //maxes are here used as a base to place the smaller ones 
// 	jackobstahl = makeJacobsthalDeque(pairsSize); // make jackobsthal suite, until we reach pairsize
// 	pos.resize(keys.size());
// 	for (size_t k = 0; k < keys.size(); k++){
// 		size_t p = keys[k];
// 		pos[p] = k;
// 	}
// 	if (pairsSize > 0)
// 		order.push_back(0);
// 	buildJacobsthalInsertionOrderDeque(order, jackobstahl, pairsSize);
// 	insertMinsByJacobsthalOrderDeque(result, order, mins, pos);
// 	if (hasStraggler)
// 		placeStragglerDeque(result, straggler);
// 	this->resDeque = result;
// }

