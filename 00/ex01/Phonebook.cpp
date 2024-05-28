/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:30:33 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/22 15:39:42 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_size = 0;
	this->_oldest_id = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

std::string	Phonebook::_trunc(std::string s, size_t size) const
{
	std::string	s2;

	s2 = s;
	if (size < 1)
		s2 = "";
	if (s2.length() > size)
	{
		s2.resize(size);
		s2[size - 1] = '.';
	}
	return (s2);
}

bool	Phonebook::_add(Contact contact)
{
	if (!contact.is_valid())
		return (false);
	if (this->_size < CONTACT_MAX)
	{
		this->_contacts[this->_size] = contact;
		this->_size++;
	}
	else
	{
		this->_contacts[this->_oldest_id] = contact;
		this->_oldest_id = (this->_oldest_id + 1) % CONTACT_MAX;
	}
	return (true);
}

void	Phonebook::_cli_print_contacts(void) const
{
	int		i;
	int		order;

	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << std::endl;
	i = (this->_size + this->_oldest_id - 1) % this->_size;
	order = 1;
	while (order <= this->_size)
	{
		std::cout << std::setw(10) << order;
		std::cout << "|";
		std::cout << std::setw(10) << this->_trunc(this->_contacts[i].getFirstname(), 10);
		std::cout << "|";
		std::cout << std::setw(10) << this->_trunc(this->_contacts[i].getLastname(), 10);
		std::cout << "|";
		std::cout << std::setw(10) << this->_trunc(this->_contacts[i].getNickname(), 10);
		std::cout << std::endl;
		i = (this->_size + i - 1) % this->_size;
		order++;
	}
	std::cout << std::endl;
}

void	Phonebook::_cli_print_menu(void) const
{
	Cli::title("PHONEBOOK");
	std::cout << " - HELP" << Txt::FAINT << "\t\tDisplay the commands" << Txt::RESET << std::endl;
	std::cout << " - ADD" << Txt::FAINT << "\t\tSave a new contact" << Txt::RESET << std::endl;
	std::cout << " - SEARCH" << Txt::FAINT << "\tDisplay a specific contact" << Txt::RESET << std::endl;
	std::cout << " - EXIT" << Txt::FAINT << "\t\tQuit the program" << Txt::RESET << std::endl;
	std::cout << std::endl;
}

bool	_is_valid_cmd(std::string s)
{
	return (s == "ADD" || s == "SEARCH" || s == "EXIT" || s == "HELP");
}

bool	Phonebook::_cli_read_cmd(std::string &cmd) const
{
	std::string input;
	
	if (std::cin.eof())
		return (false);
	while (!_is_valid_cmd(input))
	{
		if (!Cli::field("Choose an action (ex: HELP)", input, true, _is_valid_cmd))
			return (false);
	}
	cmd = input;
	return (true);
}

void	Phonebook::_cli_add(void)
{
	Contact		new_contact;

	Cli::title("ADD CONTACT");
	if (!new_contact.cli_init())
		return ;
	Cli::msg("Contact saved");
	this->_add(new_contact);
}

void	Phonebook::_cli_search(void) const
{
	std::string	input;
	int			order;
	int			i;

	Cli::title("DISPLAY CONTACT");
	if (this->_size == 0)
	{
		Cli::remove_previous_line();
		Cli::msg("No contact registered!");
		return ;
	}
	this->_cli_print_contacts();
	order = 0;
	while (order < 1 || order > this->_size)
	{
		if (!input.empty())
		{
			Cli::remove_previous_line();
			Cli::field_print("Enter the index of your choice", input, false);
		}
		if (!Cli::field("Enter the index of your choice", input, true, NULL))
			return ;
		order = std::atoi(input.c_str());
	}
	i = (this->_size - order + this->_oldest_id) % this->_size;
	this->_contacts[i].cli_print();
}

void	Phonebook::cli_start(void)
{
	std::string	cmd;

	this->_cli_print_menu();
	while (this->_cli_read_cmd(cmd) && cmd != "EXIT")
	{
		if (cmd == "ADD")
			this->_cli_add();
		else if (cmd == "SEARCH")
			this->_cli_search();
		else if (cmd == "HELP")
			this->_cli_print_menu();
	}
	if (cmd == "EXIT")
		Cli::msg("See you soon...");
	else
		Cli::msg("Program closed unexpectedly");
}
