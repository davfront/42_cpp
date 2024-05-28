/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:03:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 18:30:02 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm::AForm("Robotomy Request", 72, 45),
	_target("Undefined_target")
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "RobotomyRequestForm targetting " << this->_target << " created (default)." << Txt::RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target):
	AForm::AForm("Robotomy Request", 72, 45),
	_target(target)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "RobotomyRequestForm targetting " << this->_target << " created (with parameters)." << Txt::RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
	AForm::AForm(src),
	_target(src.getTarget())
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "RobotomyRequestForm targetting " << this->_target << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "RobotomyRequestForm targetting " << this->_target << " destroyed." << Txt::RESET << std::endl;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	AForm::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << executor.getName() << " attempts to execute the form `" << this->getName() << "`." << Txt::RESET << std::endl;
	this->testExecutionBy(executor);

	std::srand(std::time(NULL));
	int	i = std::rand();

	if (i % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy of " << this->_target << " failed." << std::endl;
}

std::ostream &	RobotomyRequestForm::print(std::ostream & o) const
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
