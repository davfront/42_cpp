/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:14 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 18:11:57 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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

	try {
		Intern intern;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> AForm* form = intern.makeForm(\"Agreement\", \"Home\");" << Txt::RESET << std::endl;
			AForm* form = intern.makeForm("Agreement", "Home");
			if (form)
				std::cout << *form << std::endl;
			delete form;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> AForm* form_SCF = intern.makeForm(\"Shrubbery Creation\", \"Home\");" << Txt::RESET << std::endl;
			AForm* form_SCF = intern.makeForm("Shrubbery Creation", "Home");
			if (form_SCF)
				std::cout << *form_SCF << std::endl;
			delete form_SCF;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> AForm* form_RRF = intern.makeForm(\"Robotomy Request\", \"Home\");" << Txt::RESET << std::endl;
			AForm* form_RRF = intern.makeForm("Robotomy Request", "Home");
			if (form_RRF)
				std::cout << *form_RRF << std::endl;
			delete form_RRF;

		std::cout << std::endl;
			std::cout << Txt::CYAN << "> AForm* form_PPF = intern.makeForm(\"Presidential Pardon\", \"Home\");" << Txt::RESET << std::endl;
			AForm* form_PPF = intern.makeForm("Presidential Pardon", "Home");
			if (form_PPF)
				std::cout << *form_PPF << std::endl;
			delete form_PPF;

		std::cout << std::endl;

	} catch(std::exception & e) {
		std::cerr << Txt::RED << "Error: " << e.what() << Txt::RESET << std::endl;
	}

	return (0);
}
