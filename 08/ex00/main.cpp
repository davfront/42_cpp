/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:26:07 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/19 13:51:06 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main (void)
{
	std::cout << std::endl;
	std::cout << "=== Find in vector ===" << std::endl;

	std::vector<int> v;
	v.push_back(0);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	std::cout << "*easyfind(v, 20): ";
	try {
		std::cout << *easyfind(v, 20) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "*easyfind(v, 25): ";
	try {
		std::cout << *easyfind(v, 25) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	// ====================================================================================== //

	std::cout << std::endl;
	std::cout << "=== Find in list ===" << std::endl;

	std::list<int> l;
	l.push_back(0);
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);

	std::cout << "*easyfind(l, 20): ";
	try {
		std::cout << *easyfind(l, 20) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "*easyfind(l, 25): ";
	try {
		std::cout << *easyfind(l, 25) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	// ====================================================================================== //

	std::cout << std::endl;
	return (0);
}
