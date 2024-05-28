/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:40 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 03:11:13 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap("Unnamed_clap_name", 100, 50, 30),
	ScavTrap(),
	FragTrap(),
	_name("Unnamed")
{
	std::cout << Txt::FAINT << "DiamondTrap " << this->_name << " created (default)." << Txt::RESET << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string const & name):
	ClapTrap(name + "_clap_name", 100, 50, 30),
	ScavTrap(),
	FragTrap(),
	_name(name)
{
	std::cout << Txt::FAINT << "DiamondTrap " << this->_name << " created (with name)." << Txt::RESET << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name = src._name;
	std::cout << Txt::FAINT << "DiamondTrap " << this->_name << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & rhs)
{
	FragTrap::operator=(rhs);
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << Txt::FAINT << "DiamondTrap " << this->_name << " destroyed." << Txt::RESET << std::endl;
	return ;
}


std::string const &	DiamondTrap::getDiamondName(void) const
{
	return (this->_name);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << " (" << ClapTrap::_name <<")" << std::endl;
}

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & x)
{
	o << "[DiamondTrap: " << Txt::CYAN << x.getDiamondName() << Txt::RESET \
		<< ", ClapTrap: " << Txt::CYAN << x.getName() << Txt::RESET \
		<< ", HP: " << Txt::CYAN << x.getHitPoints() << Txt::RESET \
		<< ", EP: " << Txt::CYAN << x.getEnergyPoints() << Txt::RESET \
		<< ", AD: " << Txt::CYAN << x.getAttackDamage() << Txt::RESET \
		<< "]";
	return (o);
}
