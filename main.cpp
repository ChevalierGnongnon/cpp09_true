/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:40:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/09/30 16:39:22 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Date.hpp"
#include "BitcoinExchange.hpp"


int main(int argc, char **argv){
    
    if (argc == 2){
        std::fstream dataBase(argv[1], std::ios::in);
        if (dataBase.is_open()){
            BitcoinExchange parser(dataBase);
            return (0);
        }
        std::cerr << "error: file inexistant or permission denied" << std::endl;
        return (1);
    }
    std::cerr << "error: invalid arguments : ./btc <filename>" << std::endl;
    return (1);
}