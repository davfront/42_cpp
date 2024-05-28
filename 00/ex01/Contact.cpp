/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:29:08 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/14 09:05:51 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_firstname = "";
	this->_lastname = "";
	this->_nickname = "";
	this->_phone = "";
	this->_secret = "";
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstname(void) const
{
	return (this->_firstname);
}

std::string	Contact::getLastname(void) const
{
	return (this->_lastname);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

bool	Contact::is_valid(void) const
{
	return (
		!this->_firstname.empty() &&
		!this->_lastname.empty() &&
		!this->_nickname.empty() &&
		!this->_phone.empty() &&
		!this->_secret.empty()
	);
}

bool	Contact::cli_init(void)
{
	if (!Cli::field("First name", this->_firstname, true, NULL))
		return (false);
	if (!Cli::field("Last name", this->_lastname, true, NULL))
		return (false);
	if (!Cli::field("Nickname", this->_nickname, true, NULL))
		return (false);
	if (!Cli::field("Phone number", this->_phone, true, NULL))
		return (false);
	if (!Cli::field("Darkest secret", this->_secret, true, NULL))
		return (false);
	return (this->is_valid());
}

void	Contact::cli_print(void) const
{
	std::cout << std::endl;

	std::cout << Txt::BLUE;
	std::cout << std::setw(16) << "First name  ";
	std::cout << Txt::RESET;
	std::cout << this->_firstname << std::endl;
	
	std::cout << Txt::BLUE;
	std::cout << std::setw(16) << "Last name  ";
	std::cout << Txt::RESET;
	std::cout << this->_lastname << std::endl;
	
	std::cout << Txt::BLUE;
	std::cout << std::setw(16) << "Nickname  ";
	std::cout << Txt::RESET;
	std::cout << this->_nickname << std::endl;
	
	std::cout << Txt::BLUE;
	std::cout << std::setw(16) << "Phone number  ";
	std::cout << Txt::RESET;
	std::cout << this->_phone << std::endl;
	
	std::cout << Txt::BLUE;
	std::cout << std::setw(16) << "Secret  ";
	std::cout << Txt::RESET;
	std::cout << this->_secret << std::endl;

	std::cout << std::endl;
}
