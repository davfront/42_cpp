/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:13:06 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/18 16:57:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

int	main(void)
{
	std::cout << std::endl;
	std::cout << "=== Construction with no parameter ===" << std::endl;

	Array<int> arr0;
	std::cout << "arr0: " << arr0 << std::endl;
	
	// ====================================================================================== //

	std::cout << std::endl;
	std::cout << "=== Construction with size ===" << std::endl;

	Array<int> arr1(5);
	std::cout << "arr1: " << arr1 << std::endl;
	for (size_t i = 0; i < arr1.size(); i++) {
		arr1[i] = i * 10;
	}
	std::cout << "arr1: " << arr1 << std::endl;
	
	// ====================================================================================== //
	
	std::cout << std::endl;
	std::cout << "=== Construction with copy ===" << std::endl;

	Array<int> arr2(arr1);
	std::cout << "arr2: " << arr2 << std::endl;
	for (size_t i = 0; i < arr2.size(); i++) {
		arr2[i] *= -1;
	}
	std::cout << "arr1: " << arr1 << std::endl;
	std::cout << "arr2: " << arr2 << std::endl;
	
	// ====================================================================================== //
	
	std::cout << std::endl;
	std::cout << "=== Assignment operator ===" << std::endl;
	
	arr2 = arr0;
	std::cout << "arr2: " << arr2 << std::endl;
	arr2 = arr1;
	std::cout << "arr2: " << arr2 << std::endl;
	
	// ====================================================================================== //
	
	std::cout << std::endl;
	std::cout << "=== Out of bound index ===" << std::endl;
	
	try {
		std::cout << "arr2[4]: " << arr2[4] << std::endl;
		std::cout << "arr2[5]: " << arr2[5] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	// ====================================================================================== //
	
	std::cout << std::endl;
	std::cout << "=== String ===" << std::endl;

	Array<std::string> arr_string(5);
	std::cout << "arr_string: " << arr_string << std::endl;
	for (size_t i = 0; i < arr_string.size(); i++) {
		std::stringstream ss;
		ss << "string" << i + 1;
		arr_string[i] = ss.str();
	}
	std::cout << "arr_string: " << arr_string << std::endl;
	
	// ====================================================================================== //
	
	std::cout << std::endl;
	std::cout << "=== Boolean ===" << std::endl;

	Array<bool> arr_bool(12);
	std::cout << "arr_bool: " << arr_bool << std::endl;
	for (size_t i = 0; i < arr_bool.size(); i++) {
		arr_bool[i] = (i % 3 == 0);
	}
	std::cout << "arr_bool: " << arr_bool << std::endl;

	return (0);
}

