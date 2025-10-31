/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:45:26 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/31 11:21:12 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"


BitcoinExchange::BitcoinExchange(std::fstream &dataFile, std::fstream &valueFile){
    loadData(this->dataCSV, dataFile, ',');
	loadData(this->valuesCSV, valueFile, '|');
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
	this->dataCSV = src.dataCSV;
	this->valuesCSV = src.valuesCSV;
}

BitcoinExchange::~BitcoinExchange(){
	
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src){
    if (this != &src){
        this->dataCSV = src.dataCSV;
		this->valuesCSV = src.valuesCSV;
    }
    return (*this);
}

void BitcoinExchange::loadData(std::multimap<Date, float> &target, std::fstream &file, char sep){
    std::string                     line;
    int                             lineNumber = 1;
    
    while (std::getline(file, line)){
        parseLine(target, line, sep, lineNumber);
        lineNumber++;
    }
}

float			BitcoinExchange::getRate(const Date &date) const{
	std::multimap<Date, float>::const_iterator it = this->dataCSV.begin();
	std::multimap<Date, float>::const_iterator prev = this->dataCSV.end();
	
	if (this->dataCSV.empty())
		throw (std::runtime_error("empty rates"));
	while (it != this->dataCSV.end() && it->first < date){
		prev = it;
		++it;
	}
	if (it != this->dataCSV.end()){
		if (!(date < it->first) && !(it->first < date)){
			return (it->second);
		}
	}
	if (prev != this->dataCSV.end())
		return (prev->second);
	throw (std::runtime_error("no earlier rate"));
}

int BitcoinExchange::sepCheck(const std::string &line, char sep){
    int place = -1;
    int n = 0;
    
    for (int i = 0; i < (int)line.size(); ++i){
        if (line[i] == sep){
            n++;
            if (n == 1)
                place = i;
            else if (n == 2)
                return (-1);
        }
    }
    if (n != 1)
        return (-1);
    return (place);
}

bool BitcoinExchange::checkIsNum(const std::string &value){
    if (value.empty())
        return (false);
    for (size_t i = 0; i < value.size(); i++){
        if (value[i] < '0' || value[i] > '9')
            return (false);
    }
    return (true);
}

std::string BitcoinExchange::cutSpaces(const std::string &tmp){
	int	i = 0;
	int	j = tmp.size() - 1;
	
	while (i < (int)tmp.size() && std::isspace((unsigned char)tmp[i]))
		i++;
	while (j >= i && std::isspace((unsigned char)tmp[j]))
		j--;
	if (i > j)
		return ("");
	return(tmp.substr(i, j - i + 1));
}

Date BitcoinExchange::parseDate(const std::string &line){
    std::string ys, ms, ds;
	
    if (line.size() == 10 && (line[4] != '-' || line[7] != '-'))
        return (Date(-1, -1, -1));
    if ((line.size() == 10) && line[4] == '-' && line[7] == '-'){
        ys = line.substr(0, 4);
        ms = line.substr(5, 2);
        ds = line.substr(8, 2);
        if (checkIsNum(ys) && checkIsNum(ms) && checkIsNum(ds))
            return (Date(std::atoi(ys.c_str()), std::atoi(ms.c_str()), std::atoi(ds.c_str())));
    }
    return (Date(-1, -1, -1));
}

bool BitcoinExchange::checkIsValidFloat(const std::string &s) {
    bool	hasDigit = false;
    bool	hasDot = false;
	size_t	i = 0;
	
	if (s.empty())
		return (false);
    if (s[i] == '+' || s[i] == '-') {
        ++i;
        if (i == s.size())
			return (false);
    }
    for (; i < s.size(); ++i) {
        
        if (s[i] >= '0' && s[i] <= '9')
            hasDigit = (true);
        else if (s[i] == '.') {
            if (hasDot)
				return false;
			hasDot = true;
			if (i + 1 >= s.size())
				return false;
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				return false;
        }
		else
            return (false);
    }
    return (hasDigit);
}

float		BitcoinExchange::parseValue(const std::string &valueString){
	if (!checkIsValidFloat(valueString))
		return (-1.0f);
	std::istringstream iss(valueString);
    float v = 0.0f;
	 iss >> v;
    if (iss.fail())
        return (-1.0f);
    if (!iss.eof())
        return (-1.0f);
    return (v);
}

void		BitcoinExchange::parseLine(std::multimap<Date, float> &target, const std::string &line, char sep, int lineNumber){
    std::string dateString;
    std::string valueString;
    std::string tmp;
    int         sepPos = sepCheck(line, sep);
	float		value;
    
    if (sepPos < 1 || sepPos >= (int)line.size() - 1)
        return (errorBadInput(line, lineNumber));
    try{
        tmp = line.substr(0, sepPos);
        dateString = cutSpaces(tmp);
        tmp = "";
    } catch (const std::out_of_range &e){
        return (errorBadInput(line, lineNumber));
	}
    try{
        tmp = line.substr(sepPos + 1);
        valueString = cutSpaces(tmp);
        tmp = "";
    } catch (const std::out_of_range &e){
        return (errorBadInput(line, lineNumber));
    }
    if (valueString.empty()){
		return (errorBadInput(line, lineNumber));	
	}
	if (lineNumber == 1 && sep == '|' && (dateString == "date" || dateString == "Date") && ((valueString == "value" || valueString == "Value"))){
		return ;
	}
	if (lineNumber == 1 && sep == ',' && (dateString == "date" || dateString == "Date") && ((valueString == "exchange_rate"))){
		return ;
	}
    if (dateString.size() != 10)
        return (errorBadInput(line, lineNumber));
    if (dateString.size() == 10){
        Date newOne = parseDate(dateString);
        if (!newOne.getIsValid())
            return (errorBadInput(line, lineNumber));
		value = parseValue(valueString);
		if (value == -1.0f)
			return (errorBadInput(line, lineNumber));
		if (sep == '|'){
			if (value < 0.0f)
				return (errorNotPositive(line, lineNumber));
			if (value > 1000.0f)
				return (errorTooLargeNumber(line, lineNumber));
		}
		else {
			if (value < 0.0f)
				return (errorBadInput(line, lineNumber));
		}
		target.insert(std::multimap<Date, float>::value_type(newOne, value));
	}
}

static std::string formatDate(const Date &d){
    std::ostringstream oss;
    oss << d.getYear() << "-" << std::setw(2) << std::setfill('0') << d.getMonth() << "-" << std::setw(2) << std::setfill('0') << d.getDay();
    return (oss.str());
}

void	BitcoinExchange::evaluate() const{
	std::multimap<Date, float>::const_iterator	it;
	
	for (it = this->valuesCSV.begin(); it != this->valuesCSV.end(); ++it){
		const Date	&d = it->first;
		float		value = it->second;
		float		rate;

		try{
			rate = this->getRate(d);
			std::cout << formatDate(d) << " => " << value << " = " << (rate * value) << std::endl;
		} catch (const std::exception &e){
            std::cerr << "Error: no earlier rate for " << formatDate(d) << std::endl;
        }
	}
}

