/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:48:38 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/26 23:00:44 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int	main(void)
{

	std::cout << std::endl;
	std::cout << "=== Test from subject ===" << std::endl;

	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	
	// ====================================================================================== //

	std::cout << std::endl;
	std::cout << "=== Exception: Not enough elements ===" << std::endl;

	{
		Span sp = Span(5);
		std::cout << sp << std::endl;
		
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << std::endl;

		sp.addNumber(6);
		std::cout << sp << std::endl;
		
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << std::endl;

		sp.addNumber(-34);
		std::cout << sp << std::endl;
		
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	// ====================================================================================== //

	std::cout << std::endl;
	std::cout << "=== Exception: Overflow ===" << std::endl;

	{
		Span sp = Span(5);
		std::cout << sp << std::endl;

		std::srand(std::time(NULL));
		try {
			unsigned int i = 1;
			while (true) {
				std::cout << "addNumber #" << i << ": ";
				sp.addNumber(rand() % 100);
				std::cout << sp << std::endl;
				i++;
			}
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}

	}
	
	// ====================================================================================== //

	std::cout << std::endl;
	std::cout << "=== Function: addNumbers ===" << std::endl;

	{
		Span sp = Span(10);
		std::cout << sp << std::endl;
		
		std::vector<int> v;
		for (int i = 0; i < 20; i++)
			v.push_back(i);
		std::vector<int>::iterator begin = v.begin();

		try {
			std::cout << std::endl << "addNumbers [0, 3]: " << std::endl;
			sp.addNumbers(begin, begin + 3);
			std::cout << sp << std::endl;
		
			std::cout << std::endl << "addNumbers [10, 15]: " << std::endl;
			sp.addNumbers(begin + 10, begin + 15);
			std::cout << sp << std::endl;
		
			std::cout << std::endl << "addNumbers [5, 9]: " << std::endl;
			sp.addNumbers(begin + 5, begin + 9);
			std::cout << sp << std::endl;
		} catch(std::exception & e) {
			std::cout << e.what() << std::endl;
			std::cout << sp << std::endl;
		}
		
	}
	
	// ====================================================================================== //

	std::cout << std::endl;
	std::cout << "=== More than 10000 numbers ===" << std::endl;

	{
		unsigned int n = 10000 * 100;
		Span sp = Span(n);
		for (unsigned int i = 0; i < n; i++)
			sp.addNumber(rand() % n);
		std::cout << "Collection of " << sp.getCollection().size() << " numbers" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
	}

	// ====================================================================================== //
	std::cout << std::endl;
	return (0);
}
