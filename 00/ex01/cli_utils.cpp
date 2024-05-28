/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:28:54 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/22 15:45:11 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli_utils.hpp"

void	Cli::title(std::string title)
{
	std::cout << std::endl;
	std::cout << Txt::BLUE << Txt::BOLD << Txt::UNDERLINE << title << Txt::RESET;
	std::cout << std::endl << std::endl;
}

void	Cli::msg(std::string msg)
{
	std::cout << std::endl;
	std::cout << Txt::PURPLE << "⇨  " << msg << Txt::RESET << std::endl;
	std::cout << std::endl;
}

void	Cli::remove_previous_line(void)
{
	std::cout << Txt::MOVEUP << Txt::CLEAR;
}

bool	Cli::field_read(std::string label, std::string &value)
{
	std::string	input;

	if (std::cin.eof())
		return (false);
	std::cout << Txt::BLUE << "? " << Txt::RESET;
	std::cout << Txt::BOLD << label << Txt::RESET;
	std::cout << Txt::FAINT << " » " << Txt::RESET;
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		std::cout << std::endl;
		return (false);
	}
	value = input;
	return (true);
}

void	Cli::field_print(std::string label, std::string value, bool is_valid)
{
	if (!std::cin.eof() && is_valid)
		std::cout << Txt::GREEN << "✓ " << Txt::RESET;
	else
		std::cout << Txt::RED << "✗ " << Txt::RESET;
	std::cout << Txt::BOLD << label << Txt::RESET;
	std::cout << Txt::FAINT << " » " << Txt::RESET;
	std::cout << value;
	if (std::cin.eof())
		std::cout << Txt::RED << "\t\tAborted" << Txt::RESET;
	else if (!is_valid)
		std::cout << Txt::RED << "\t\tInvalid" << Txt::RESET;
	std::cout << std::endl;
}

bool	Cli::field(std::string label, std::string &value, bool is_required = true, bool (*is_valid)(std::string) = NULL)
{
	std::string	input;

	if (std::cin.eof())
		return (false);
	Cli::field_read(label, input);
	while (!std::cin.eof() && is_required && input.empty())
	{
		Cli::remove_previous_line();
		Cli::field_read(label, input);
	}
	Cli::remove_previous_line();
	Cli::field_print(label, input, !is_valid || is_valid(input));
	value = input;
	return (true);
}
