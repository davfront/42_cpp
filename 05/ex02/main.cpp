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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <stdexcept>

void	printTitle(std::string const & title)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main(void)
{

	Bureaucrat alan("Alan", 150);
	Bureaucrat bill("Bill", 20);
	Bureaucrat chris("Chris", 3);
	ShrubberyCreationForm form_SCF("SCF");
	RobotomyRequestForm form_RRF("RRF");
	PresidentialPardonForm form_PPF("PPF");
	
	printTitle("UNSIGNED FORM EXCEPTIONS");
	{
		try {

			std::cout << std::endl;
				std::cout << chris << std::endl;
				std::cout << form_SCF << std::endl;
				std::cout << form_RRF << std::endl;
				std::cout << form_PPF << std::endl;

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> chris.executeForm(form_SCF);" << Txt::RESET << std::endl;
				chris.executeForm(form_SCF);

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> chris.executeForm(form_RRF);" << Txt::RESET << std::endl;
				chris.executeForm(form_RRF);

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> chris.executeForm(form_PPF);" << Txt::RESET << std::endl;
				chris.executeForm(form_PPF);

		} catch (std::exception & e) {
			std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
		}
	}
	
	printTitle("GRADE TOO LOW EXCEPTIONS");
	{
		try {
			form_SCF.beSigned(bill);
			form_RRF.beSigned(bill);
			form_PPF.beSigned(bill);

			std::cout << std::endl;
				std::cout << alan << std::endl;
				std::cout << form_SCF << std::endl;
				std::cout << form_RRF << std::endl;
				std::cout << form_PPF << std::endl;

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> alan.executeForm(form_SCF);" << Txt::RESET << std::endl;
				alan.executeForm(form_SCF);

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> alan.executeForm(form_RRF);" << Txt::RESET << std::endl;
				alan.executeForm(form_RRF);

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> alan.executeForm(form_PPF);" << Txt::RESET << std::endl;
				alan.executeForm(form_PPF);

		} catch (std::exception & e) {
			std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
		}
	}

	printTitle("EXECUTE SCF");
	{
		try {

			form_SCF.beSigned(bill);

			std::cout << std::endl;
				std::cout << bill << std::endl;
				std::cout << form_SCF << std::endl;

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> bill.executeForm(form_SCF);" << Txt::RESET << std::endl;
				bill.executeForm(form_SCF);

		} catch (std::exception & e) {
			std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
		}
	}

	printTitle("EXECUTE RRF");
	{
		try {

			form_RRF.beSigned(bill);

			std::cout << std::endl;
				std::cout << bill << std::endl;
				std::cout << form_RRF << std::endl;

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> bill.executeForm(form_RRF);" << Txt::RESET << std::endl;
				bill.executeForm(form_RRF);

		} catch (std::exception & e) {
			std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
		}
	}

	printTitle("EXECUTE PPF");
	{
		try {

			form_PPF.beSigned(bill);

			std::cout << std::endl;
				std::cout << form_PPF << std::endl;
				std::cout << chris << std::endl;

			std::cout << std::endl;
				std::cout << Txt::CYAN << "> chris.executeForm(form_PPF);" << Txt::RESET << std::endl;
				chris.executeForm(form_PPF);

		} catch (std::exception & e) {
			std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
		}
	}
	
	std::cout << std::endl;

	return (0);
}
