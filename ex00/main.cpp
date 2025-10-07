/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:40:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/10/07 13:46:37 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::fstream dataFile("data.csv", std::ios::in);
	if (!dataFile.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::fstream valueFile(argv[1], std::ios::in);
	if (!valueFile.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange ex(dataFile, valueFile);
	ex.evaluate();
	return (0);
}