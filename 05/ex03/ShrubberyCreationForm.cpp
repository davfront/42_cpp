/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:03:30 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 18:30:06 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm::AForm("Shrubbery Creation", 145, 137),
	_target("Undefined_target")
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "ShrubberyCreationForm targetting " << this->_target << " created (default)." << Txt::RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target):
	AForm::AForm("Shrubbery Creation", 145, 137),
	_target(target)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "ShrubberyCreationForm targetting " << this->_target << " created (with parameters)." << Txt::RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
	AForm::AForm(src),
	_target(src.getTarget())
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "ShrubberyCreationForm targetting " << this->_target << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "ShrubberyCreationForm targetting " << this->_target << " destroyed." << Txt::RESET << std::endl;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	AForm::operator=(rhs);
	this->_target = rhs.getTarget();
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << executor.getName() << " attempts to execute the form `" << this->getName() << "`." << Txt::RESET << std::endl;
	this->testExecutionBy(executor);

	std::string		filename(this->_target + "_shrubbery");
	std::ofstream	ofs(filename.c_str());

	if (!ofs)
		std::cerr << "The file " << filename << " cannot be opened." << std::endl;
    ofs << "      ^  " << "      ^  " << "      ^  " << std::endl;
    ofs << "     ^^^ " << "     ^^^ " << "     ^^^ " << std::endl;
    ofs << "    ^^^^^" << "    ^^^^^" << "    ^^^^^" << std::endl;
    ofs << "      |  " << "      |  " << "      |  " << std::endl;
	ofs.close();
}

std::ostream &	ShrubberyCreationForm::print(std::ostream & o) const
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
