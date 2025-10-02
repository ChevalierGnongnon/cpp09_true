/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:44:48 by chhoflac          #+#    #+#             */
/*   Updated: 2025/09/16 16:32:56 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <iomanip>

Date::Date(int year, int month, int day):year(year), month(month), day(day){
	this->isLeapDate = this->isLeap();
	this->isValidDate = this->isValid();
}

Date::Date(const Date &src): year(src.year), month(src.month), day(src.day){
    this->isLeapDate = isLeap();
	this->isValidDate = isValid();
}

Date &Date::operator=(const Date &src){
	if (this != &src){
		this->day = src.day;
		this->month = src.month;
		this->year = src.year;
		this->isLeapDate = isLeap();
		this->isValidDate = isValid();
	}
	return (*this);
}

Date::~Date(){
	
}
int                 Date::getDay() const{
	return (this->day);	
}
int                 Date::getMonth() const{
	return (this->month);	
}
int                 Date::getYear() const{
	return (this->year);
}

bool Date::getIsLeap() const{
	return (this->isLeapDate);
}
bool Date::getIsValid() const{
	return (this->isValidDate);
}

bool Date::operator<(const Date &other) const{
    if (this->year != other.year)
		return (this->year < other.year);
	if (this->month != other.month)
		return (this->month < other.month);
	if (this->day != other.day)
		return (this->day < other.day);
	return (false);
}

bool Date::operator>(const Date &other) const{
    if (this->year != other.year)
		return (this->year > other.year);
	if (this->month != other.month)
		return (this->month > other.month);
	if (this->day != other.day)
		return (this->day > other.day);
	return (false);
}

bool Date::isValid() const{
	int maxDay = 31;

	if (this->month < 1 || this->month > 12)
		return (false);
	if (this->day < 1)
		return (false);
	if (this->month == 2) {
		if (this->isLeapDate)
			maxDay = 29;
		else
			maxDay = 28;
	}
	else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
		maxDay = 30;
	if (this->day > maxDay)
		return false;
	return true;
}


bool Date::isLeap() const{
	return ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0));
}

std::ostream &operator<<(std::ostream &os, const Date &date){
	std::ostream::fmtflags f = os.flags();
	char oldFill = os.fill();
    os << date.getYear() << '-'
       << std::setw(2) << std::setfill('0') << date.getMonth() << '-'
       << std::setw(2) << std::setfill('0') << date.getDay();
    os.flags(f);
	os.fill(oldFill);
    return (os);
}
