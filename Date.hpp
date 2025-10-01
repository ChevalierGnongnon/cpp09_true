/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:10:55 by chhoflac          #+#    #+#             */
/*   Updated: 2025/09/16 16:31:32 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Date {
	private:
		int		year;
		int		month;
		int		day;
		bool	isLeapDate;
		bool	isValidDate;
		Date();
	public:
		Date(int year, int month, int day);
		Date(const Date &src);
		Date &operator=(const Date &src);
		~Date();
		
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		bool getIsLeap() const;
		bool getIsValid() const;

		
		bool isValid() const;
		bool operator<(const Date &otherOne) const;
		bool operator>(const Date &otherOne) const;
		bool isLeap() const;
};
std::ostream &operator<<(std::ostream &os, const Date &date);
