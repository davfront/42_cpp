/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:26:59 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 21:19:57 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::t_level const	Harl::_levels[4] = {
	{
		.id = "DEBUG",
		.fn = &Harl::_debug
	},
	{
		.id = "INFO",
		.fn = &Harl::_info
	},
	{
		.id = "WARNING",
		.fn = &Harl::_warning
	},
	{
		.id = "ERROR",
		.fn = &Harl::_error
	}
};

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level) const
{
	for (size_t	i = 0; i < 4; i++) {
		if (level == Harl::_levels[i].id)
			(this->*(Harl::_levels[i].fn))();
	}
}

void	Harl::_debug(void) const
{
	std::cout << "[DEBUG] " \
	<< "I love having extra bacon for my " \
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. " \
	<< "I really do!" \
	<< std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "[INFO] " \
	<< "I cannot believe adding extra bacon costs more money. " \
	<< "You didn't put enough bacon in my burger! " \
	<< "If you did, I wouldn't be asking for more!" \
	<< std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "[WARNING] " \
	<< "I think I deserve to have some extra bacon for free. " \
	<< "I've been coming for years whereas " \
	<< "you started working here since last month." \
	<< std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "[ERROR] " \
	<< "This is unacceptable! I want to speak to the manager now." \
	<< std::endl;
}
