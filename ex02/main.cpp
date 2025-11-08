/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:08:40 by chhoflac          #+#    #+#             */
/*   Updated: 2025/11/08 13:40:18 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2){
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::string input;
	for (int i = 1; i < argc; i++){
		input += argv[i];
		if (i + 1 < argc)
			input += " ";
	}
	try{
		PMergeMe test(input);
		// std::cout << "Before: " << test.getInput() << std::endl;

		// double timeVect = test.runVectorPipelineUs();
		// double timeDeque = test.runDequePipelineUs();

		// std::cout << "After: ";
		// test.showResVector();
		// std::cout << std::endl;

		// std::cout << std::fixed << std::setprecision(5);

		// std::cout << "Time to process a range of "
		// 		  << test.getVect().size()
		// 		  << " elements with std::vector : "
		// 		  << timeVect << " us" << std::endl;

		// std::cout << "Time to process a range of "
		// 		  << test.getCont().size()
		// 		  << " elements with std::deque : "
		// 		  << timeDeque << " us" << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}