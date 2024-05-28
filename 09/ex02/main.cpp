/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:14:38 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/28 17:48:57 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Error: At least on argument expected" << std::endl;
		return (1);
	}

	try {
		PmergeMe pm(argc - 1, argv + 1);
		pm.run();
	} catch(std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
