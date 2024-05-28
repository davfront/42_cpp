/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:00:49 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 12:42:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int const	Bureaucrat::_lowestGrade = 150;
int const	Bureaucrat::_highestGrade = 1;

Bureaucrat::Bureaucrat(void):
	_name("Unnamed"),
	_grade(Bureaucrat::_lowestGrade)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Bureaucrat " << this->_name << " created (default)." << Txt::RESET << std::endl;
	this->testGrade();
	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade):
	_name(name),
	_grade(grade)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Bureaucrat " << this->_name << " created (with parameters)." << Txt::RESET << std::endl;
	this->testGrade();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src):
	_name(src.getName()),
	_grade(src.getGrade())
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Bureaucrat " << this->_name << " created (copy)." << Txt::RESET << std::endl;
	this->testGrade();
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Bureaucrat " << this->_name << " destroyed." << Txt::RESET << std::endl;
	return ;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs.getGrade();
	this->testGrade();
	return (*this);
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const &	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::testGrade(void) const
{
	if (this->_grade < Bureaucrat::_highestGrade)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade > Bureaucrat::_lowestGrade)
		throw (Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::increaseGrade(void)
{
	this->_grade = this->_grade - 1;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Grade of " << this->_name << " increased to " << this->_grade << "." << Txt::RESET << std::endl;
	this->testGrade();
}

void	Bureaucrat::decreaseGrade(void)
{
	this->_grade = this->_grade + 1;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Grade of " << this->_name << " decreased to " << this->_grade << "." << Txt::RESET << std::endl;
	this->testGrade();
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
