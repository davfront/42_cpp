/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:40 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 01:02:19 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name("Unnamed"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << Txt::FAINT << "ClapTrap " << this->_name << " created (default)." << Txt::RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const & name):
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << Txt::FAINT << "ClapTrap " << this->_name << " created (with name)." << Txt::RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src):
	_name(src.getName()),
	_hitPoints(src.getHitPoints()),
	_energyPoints(src.getEnergyPoints()),
	_attackDamage(src.getAttackDamage())
{
	std::cout << Txt::FAINT << "ClapTrap " << this->_name << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << Txt::FAINT << "ClapTrap " << this->_name << " destroyed." << Txt::RESET << std::endl;
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setName(std::string const & name)
{
	this->_name = name;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void	ClapTrap::setHitPoints(unsigned int const & hitPoints)
{
	this->_hitPoints = hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void	ClapTrap::setEnergyPoints(unsigned int const & energyPoints)
{
	this->_energyPoints = energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setAttackDamage(unsigned int const & attackDamage)
{
	this->_attackDamage = attackDamage;
}	

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << ", ";
		if (this->_hitPoints <= 0)
			std::cout << "it is dead." << std::endl;
		else
			std::cout << "it is out of energy." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be attacked, it is dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is attacked, ";
	if (this->_hitPoints > amount)
	{
		this->_hitPoints -= amount;
		std::cout << "and loses " << amount << " hit points." << std::endl;
	}
	else
	{
		this->_hitPoints = 0;
		std::cout << "and dies." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be repaired, ";
		if (this->_hitPoints <= 0)
			std::cout << "it is dead." << std::endl;
		else
			std::cout << "it is out of energy." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself, it gets " << amount << " hit points back." << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
}

std::ostream &	operator<<(std::ostream & o, ClapTrap const & x)
{
	o << "[ClapTrap: " << Txt::CYAN << x.getName() << Txt::RESET \
		<< ", HP: " << Txt::CYAN << x.getHitPoints() << Txt::RESET \
		<< ", EP: " << Txt::CYAN << x.getEnergyPoints() << Txt::RESET \
		<< ", AD: " << Txt::CYAN << x.getAttackDamage() << Txt::RESET \
		<< "]";
	return (o);
}
