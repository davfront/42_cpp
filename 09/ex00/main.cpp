/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:53:41 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 10:17:08 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./btc <inputFile>" << std::endl;
		return (1);
	}

	try {
		BitcoinExchange btc("data.csv");
		btc.convertBtcFile(argv[1]);
	} catch(std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
