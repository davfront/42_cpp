/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:03:16 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 18:29:57 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm::AForm("Presidential Pardon", 25, 5),
	_target("Undefined_target")
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "PresidentialPardonForm targetting " << this->_target << " created (default)." << Txt::RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target):
	AForm::AForm("Presidential Pardon", 25, 5),
	_target(target)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "PresidentialPardonForm targetting " << this->_target << " created (with parameters)." << Txt::RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
	AForm::AForm(src),
	_target(src.getTarget())
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "PresidentialPardonForm targetting " << this->_target << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "PresidentialPardonForm targetting " << this->_target << " destroyed." << Txt::RESET << std::endl;
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	AForm::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << executor.getName() << " attempts to execute the form `" << this->getName() << "`." << Txt::RESET << std::endl;
	this->testExecutionBy(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &	PresidentialPardonForm::print(std::ostream & o) const
{
	o << "(" \
		<< "name: " << this->getName() \
		<< ", target: " << this->getTarget() \
		<< ", isSigned: " << this->getIsSigned() \
		<< ", gradeToSign: " << this->getGradeToSign() \
		<< ", gradeToExecute: " << this->getGradeToExecute() \
	<< ")";
	return (o);
}
