/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:45:26 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/01 19:05:29 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include "Date.hpp"
#include <stdexcept>
#include <cctype>

BitcoinExchange::BitcoinExchange(std::fstream &dataBase){
	std::map<Date, float>::iterator i = this->exchangeRates.begin();
    
    this->exchangeRates = loadData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
	this->exchangeRates = src.exchangeRates;
}

BitcoinExchange::~BitcoinExchange(){
	
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src){
    if (this != &src){
        this->exchangeRates = src.exchangeRates;
    }
    return (*this);
}

std::map<Date, float> BitcoinExchange::loadData(std::fstream &file){
	std::map<Date, float>           data;
    std::map<Date, float>::iterator it;
    std::string                     line;
    int                             lineNumber = 1;
    
    while (std::getline(file, line)){
        parseLine(line, '|', lineNumber);
        lineNumber++;
    }
}

static int sepCheck(const std::string &line, char sep){
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

bool checkIsNum(const std::string &value){
    if (value.empty())
        return (false);
    for (size_t i = 0; i < value.size(); i++){
        if (value[i] < '0' || value[i] > '9')
            return (false);
    }
    return (true);
}
static Date parseDate(const std::string &line){
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


void		BitcoinExchange::parseLine(const std::string &line, char sep, int lineNumber){
    std::string dateString;
    std::string valueString;
    std::string tmp;
    int         sepPos = sepCheck(line, sep);
    int         i = 0;
    int         j = 0;
    
    if (sepPos < 1 || sepPos >= (int)line.size() - 1){
        std::cerr << "Error: bad input => " << line << " (line " << lineNumber << ")" << std::endl;
        return ;
    }
    try{
        tmp = line.substr(0, sepPos);
        j = tmp.size() - 1;
        while (i < (int)tmp.size() && std::isspace((unsigned char)tmp[i]))
            i++;
        while (j >= i && std::isspace((unsigned char)tmp[j]))
            j--;
        dateString = tmp.substr(i, j - i + 1);
        tmp = "";
    } catch (const std::out_of_range &e){
        std::cerr << "Error: bad input => " << line << " (line " << lineNumber << ")" << std::endl;
        return ;
    }
    try{
        tmp = line.substr(sepPos + 1);
        i = 0;
        j = tmp.size() - 1;
        while (i < (int)tmp.size() && std::isspace((unsigned char)tmp[i]))
            i++;
        while (j >= i && std::isspace((unsigned char)tmp[j]))
            j--;
        valueString = tmp.substr(i, j - i + 1);
        tmp = "";
    } catch (const std::out_of_range &e){
        std::cerr << "Error: bad input => " << line << " (line " << lineNumber << ")" << std::endl;
        return ;
    }
    if (valueString.empty()) {
        std::cerr << "Error: bad input => " << line << " (line " << lineNumber << ")" << std::endl;
        return; 
    }
    if (dateString.size() != 10){      
        std::cerr << "Error: bad input => " << line << " (line " << lineNumber << ")" << std::endl;
        return ;
    }
    if (dateString.size() == 10){
        Date newOne = parseDate(dateString);
        if (newOne.getYear() == -1){
            std::cerr << "Error: bad input => " << line << " (line " << lineNumber << ")" << std::endl;
            return ;
        }
   }
   
}
