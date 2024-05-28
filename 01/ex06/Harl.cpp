/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:26:59 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 21:20:44 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::t_level const	Harl::_levels[4] = {
	{
		.id = "DEBUG",
		.fn = &Harl::_debug,
		.severity = 0
	},
	{
		.id = "INFO",
		.fn = &Harl::_info,
		.severity = 1
	},
	{
		.id = "WARNING",
		.fn = &Harl::_warning,
		.severity = 2
	},
	{
		.id = "ERROR",
		.fn = &Harl::_error,
		.severity = 3
	}
};

Harl::Harl(void)
{
	this->_severity_filter = 0;
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level) const
{
	if (this->_severity_filter == -1)
		return ;
	for (size_t	i = 0; i < 4; i++) {
		if (level == Harl::_levels[i].id && Harl::_levels[i].severity >= this->_severity_filter)
			(this->*(Harl::_levels[i].fn))();
	}
}

bool	Harl::setFilter(std::string level)
{
	this->_severity_filter = -1;
	for (size_t	i = 0; i < 4; i++) {
		if (level == Harl::_levels[i].id)
			this->_severity_filter = Harl::_levels[i].severity;
	}
	return (this->_severity_filter != -1);
}

void	Harl::_debug(void) const
{
	std::cout << "[ DEBUG ] " \
	<< std::endl \
	<< "I love having extra bacon for my " \
	<< "7XL-double-cheese-triple-pickle-specialketchup burger. " \
	<< "I really do!" \
	<< std::endl \
	<< std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "[ INFO ] " \
	<< std::endl \
	<< "I cannot believe adding extra bacon costs more money. " \
	<< "You didn't put enough bacon in my burger! " \
	<< "If you did, I wouldn't be asking for more!" \
	<< std::endl \
	<< std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "[ WARNING ] " \
	<< std::endl \
	<< "I think I deserve to have some extra bacon for free. " \
	<< "I've been coming for years whereas " \
	<< "you started working here since last month." \
	<< std::endl \
	<< std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "[ ERROR ] " \
	<< std::endl \
	<< "This is unacceptable! I want to speak to the manager now." \
	<< std::endl \
	<< std::endl;
}
