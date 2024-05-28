/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:36:32 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 18:19:13 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::t_createPair const	Intern::_createList[3] = {
	{
		.id = "Shrubbery Creation",
		.fn = &Intern::_createShrubberyCreationForm
	},
	{
		.id = "Robotomy Request",
		.fn = &Intern::_createRobotomyRequestForm
	},
	{
		.id = "Presidential Pardon",
		.fn = &Intern::_createPresidentialPardonForm
	}
};

Intern::Intern(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Intern created (default)." << Txt::RESET << std::endl;
	return ;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Intern created (copy)." << Txt::RESET << std::endl;
	return ;
}

Intern::~Intern(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Intern destroyed." << Txt::RESET << std::endl;
	return ;
}


Intern &	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

AForm*	Intern::makeForm(std::string const & name, std::string const & target) const
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Intern attempts to make the form `" << name << "`." << Txt::RESET << std::endl;
	AForm*	form(NULL);

	for (size_t	i = 0; i < 3; i++) {
		if (name == Intern::_createList[i].id) {
			form = (*(Intern::_createList[i].fn))(target);
			std::cout << "Intern creates `" << name << "`." << std::endl;
			return (form);
		}
	} 

	std::cerr << "Intern cannot create `" << name << "`, this form is unknown." << std::endl;
	return (form);
}

AForm*	Intern::_createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}
