/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:25:42 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/22 13:10:53 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	bool isDebugEnabled = (argc >= 2 && std::string(argv[1]) == "--debug");
	std::string usage = "Usage: ./RPN \"<RPN expression>\"";
	if (argc < 2 + isDebugEnabled) {
		std::cerr << "Error: Missing argument" << std::endl;
		std::cerr << usage << std::endl;
		return (1);
	}
	if (argc > 2 + isDebugEnabled) {
		std::cerr << "Error: Too many arguments" << std::endl;
		std::cerr << usage << std::endl;
		return (1);
	}

	RPN rpn(argv[1 + isDebugEnabled]);
	try {
		std::cout << rpn.solve() << std::endl;
	} catch(std::exception & e) {
		std::cerr << "Error";
		if (isDebugEnabled)
			std::cerr << ": " << e.what();
		std::cerr << std::endl;
		return (1);
	}
	return (0);
}
