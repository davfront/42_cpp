/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:11 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/13 17:52:13 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int const	Form::_lowestGrade = 150;
int const	Form::_highestGrade = 1;

Form::Form(void):
	_name("Unnamed_form"),
	_isSigned(false),
	_gradeToSign(Form::_lowestGrade),
	_gradeToExecute(Form::_lowestGrade)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Form " << this->_name << " created (default)." << Txt::RESET << std::endl;
	this->testGrades();
	return ;
}

Form::Form(std::string const & name, int const & gradeToSign, int const & gradeToExecute):
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Form " << this->_name << " created (with parameters)." << Txt::RESET << std::endl;
	this->testGrades();
	return ;
}

Form::Form(Form const & src):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_gradeToSign(src.getGradeToSign()),
	_gradeToExecute(src.getGradeToExecute())
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Form " << this->_name << " created (copy)." << Txt::RESET << std::endl;
	this->testGrades();
	return ;
}

Form::~Form(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "Form " << this->_name << " destroyed." << Txt::RESET << std::endl;
	return ;
}

Form &	Form::operator=(Form const & rhs)
{
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool const &	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int const &	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int const &	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	Form::testGrades(void) const
{
	if (this->_gradeToSign < Form::_highestGrade)
		throw (Form::GradeTooHighException());
	if (this->_gradeToSign > Form::_lowestGrade)
		throw (Form::GradeTooLowException());
	if (this->_gradeToExecute < Form::_highestGrade)
		throw (Form::GradeTooHighException());
	if (this->_gradeToExecute > Form::_lowestGrade)
		throw (Form::GradeTooLowException());
}

void	Form::beSigned(Bureaucrat const & signer)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << signer.getName() << " attempts to sign the form `" << this->getName() << "`." << Txt::RESET << std::endl;
	if (signer.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << "(" \
		<< "Form: " << rhs.getName() \
		<< ", isSigned: " << rhs.getIsSigned() \
		<< ", gradeToSign: " << rhs.getGradeToSign() \
		<< ", gradeToExecute: " << rhs.getGradeToExecute() \
	<< ")";
	return (o);
}