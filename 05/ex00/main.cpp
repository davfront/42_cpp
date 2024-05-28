/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:14 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 16:47:54 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

void	printTitle(std::string const & title)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int	main(void)
{

	printTitle("CANONICAL CLASS");
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat	a;" << Txt::RESET << std::endl;
			Bureaucrat	a;
			std::cout << "a: " << a << std::endl;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  b(\"John\", 65);" << Txt::RESET << std::endl;
			Bureaucrat	b("John", 65);
			std::cout << "b: " << b << std::endl;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  c(b);" << Txt::RESET << std::endl;
			Bureaucrat	c(b);
			std::cout << "c: " << c << std::endl;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> a = b" << Txt::RESET << std::endl;
			a = b;
			std::cout << "a: " << a << std::endl;
			
		std::cout << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}

	printTitle("GRADE EXCEPTION ON CONSTRUCTOR");
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  a(\"Brad\", -10);" << Txt::RESET << std::endl;
			Bureaucrat	a("Brad", -10);
			std::cout << "a: " << a << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  a(\"Brad\", 300);" << Txt::RESET << std::endl;
			Bureaucrat	a("Brad", 300);
			std::cout << "a: " << a << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	printTitle("GRADE EXCEPTION ON INCREASE");

	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  a(\"Brad\", 3);" << Txt::RESET << std::endl;
			Bureaucrat	a("Brad", 3);
			std::cout << "a: " << a << std::endl;

		while (1) {
			std::cout << std::endl;
				std::cout << Txt::CYAN << "> a.increaseGrade()" << Txt::RESET << std::endl;
				a.increaseGrade();
				std::cout << "a: " << a << std::endl;
		}
		
		std::cout << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	printTitle("GRADE EXCEPTION ON DECREASE");

	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  a(\"Brad\", 148);" << Txt::RESET << std::endl;
			Bureaucrat	a("Brad", 148);
			std::cout << "a: " << a << std::endl;

		while (1) {
			std::cout << std::endl;
				std::cout << Txt::CYAN << "> a.decreaseGrade()" << Txt::RESET << std::endl;
				a.decreaseGrade();
				std::cout << "a: " << a << std::endl;
		}
		
		std::cout << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}

	return 0;
}
