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

#include "Form.hpp"
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
			std::cout << Txt::CYAN << "> Form	a;" << Txt::RESET << std::endl;
			Form	a;
			std::cout << "a: " << a << std::endl;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Form  b(\"Agreement\", 10, 100);" << Txt::RESET << std::endl;
			Form	b("Agreement", 10, 100);
			std::cout << "b: " << b << std::endl;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Form  c(b);" << Txt::RESET << std::endl;
			Form	c(b);
			std::cout << "c: " << c << std::endl;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat	signer(\"President\", 1);" << Txt::RESET << std::endl;
			Bureaucrat	signer("President", 1);
			std::cout << Txt::CYAN << "> a.beSigned(signer);" << Txt::RESET << std::endl;
			a.beSigned(signer);
			std::cout << "a: " << a << std::endl;

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
			std::cout << Txt::CYAN << "> Form  a(\"Agreement\", -10, 100);" << Txt::RESET << std::endl;
			Form	a("Agreement", -10, 100);
			std::cout << "a: " << a << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Form  a(\"Agreement\", 300, 100);" << Txt::RESET << std::endl;
			Form	a("Agreement", 300, 100);
			std::cout << "a: " << a << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Form  a(\"Agreement\", 10, -10);" << Txt::RESET << std::endl;
			Form	a("Agreement", 10, -10);
			std::cout << "a: " << a << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Form  a(\"Agreement\", 10, 300);" << Txt::RESET << std::endl;
			Form	a("Agreement", 10, 300);
			std::cout << "a: " << a << std::endl;

	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}
	
	printTitle("GRADE EXCEPTION WHEN SIGNING");
	
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  signer1(\"Bill\", 3);" << Txt::RESET << std::endl;
			Bureaucrat	signer1("Bill", 3);
			std::cout << Txt::CYAN << "> Bureaucrat  signer2(\"Joe\", 90);" << Txt::RESET << std::endl;
			Bureaucrat	signer2("Joe", 90);
			std::cout << Txt::CYAN << "> Form  form(\"Agreement\", 10, 20);" << Txt::RESET << std::endl;
			Form	form("Agreement", 10, 20);
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> form.beSigned(signer1);" << Txt::RESET << std::endl;
			form.beSigned(signer1);
			std::cout << form << std::endl;
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> form.beSigned(signer2);" << Txt::RESET << std::endl;
			form.beSigned(signer2);
			std::cout << form << std::endl;


	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}

	
	try {
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> Bureaucrat  signer1(\"Bill\", 3);" << Txt::RESET << std::endl;
			Bureaucrat	signer1("Bill", 3);
			std::cout << Txt::CYAN << "> Bureaucrat  signer2(\"Joe\", 90);" << Txt::RESET << std::endl;
			Bureaucrat	signer2("Joe", 90);
			std::cout << Txt::CYAN << "> Form  form(\"Agreement\", 10, 20);" << Txt::RESET << std::endl;
			Form	form("Agreement", 10, 20);
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> signer1.signForm(form);" << Txt::RESET << std::endl;
			signer1.signForm(form);
	
		std::cout << std::endl;
			std::cout << Txt::CYAN << "> signer2.signForm(form);" << Txt::RESET << std::endl;
			signer2.signForm(form);


	} catch (std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}

	return 0;
}
