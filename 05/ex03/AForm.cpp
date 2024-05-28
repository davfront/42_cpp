/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:11 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 18:32:18 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

int const	AForm::_lowestGrade = 150;
int const	AForm::_highestGrade = 1;

AForm::AForm(void):
	_name("Unnamed_form"),
	_isSigned(false),
	_gradeToSign(AForm::_lowestGrade),
	_gradeToExecute(AForm::_lowestGrade)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "AForm `" << this->_name << "` created (default)." << Txt::RESET << std::endl;
	this->testGrades();
	return ;
}

AForm::AForm(std::string const & name, int const & gradeToSign, int const & gradeToExecute):
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "AForm `" << this->_name << "` created (with parameters)." << Txt::RESET << std::endl;
	this->testGrades();
	return ;
}

AForm::AForm(AForm const & src):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute())
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "AForm `" << this->_name << "` created (copy)." << Txt::RESET << std::endl;
	this->testGrades();
	return ;
}

AForm::~AForm(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "AForm `" << this->_name << "` destroyed." << Txt::RESET << std::endl;
	return ;
}

AForm &	AForm::operator=(AForm const & rhs)
{
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool const &	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int const &	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const &	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	AForm::testGrades(void) const
{
	if (this->_gradeToSign < AForm::_highestGrade)
		throw (AForm::GradeTooHighException());
	if (this->_gradeToSign > AForm::_lowestGrade)
		throw (AForm::GradeTooLowException());
	if (this->_gradeToExecute < AForm::_highestGrade)
		throw (AForm::GradeTooHighException());
	if (this->_gradeToExecute > AForm::_lowestGrade)
		throw (AForm::GradeTooLowException());
}

void	AForm::beSigned(Bureaucrat const & signer)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << signer.getName() << " attempts to sign the form `" << this->getName() << "`." << Txt::RESET << std::endl;
	if (signer.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
}

void	AForm::testExecutionBy(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw (AForm::UnsignedFormException());
	if (executor.getGrade() > this->_gradeToExecute)
		throw (AForm::GradeTooLowException());
}

std::ostream &	operator<<(std::ostream & o, AForm const & rhs)
{
	return (rhs.print(o));
}