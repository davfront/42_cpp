/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:40 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 02:27:30 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Unnamed", 100, 50, 20)
{
	std::cout << Txt::FAINT << "ScavTrap " << this->_name << " created (default)." << Txt::RESET << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const & name): ClapTrap(name, 100, 50, 20)
{
	std::cout << Txt::FAINT << "ScavTrap " << this->_name << " created (with name)." << Txt::RESET << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
	std::cout << Txt::FAINT << "ScavTrap " << this->_name << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << Txt::FAINT << "ScavTrap " << this->_name << " destroyed." << Txt::RESET << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " cannot switch to Gate keeper mode, it is dead." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, ScavTrap const & x)
{
	o << "[ScavTrap: " << Txt::CYAN << x.getName() << Txt::RESET \
		<< ", HP: " << Txt::CYAN << x.getHitPoints() << Txt::RESET \
		<< ", EP: " << Txt::CYAN << x.getEnergyPoints() << Txt::RESET \
		<< ", AD: " << Txt::CYAN << x.getAttackDamage() << Txt::RESET \
		<< "]";
	return (o);
}
