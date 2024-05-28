/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:40 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 01:26:39 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Unnamed", 100, 100, 30)
{
	std::cout << Txt::FAINT << "FragTrap " << this->_name << " created (default)." << Txt::RESET << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const & name): ClapTrap(name, 100, 100, 30)
{
	std::cout << Txt::FAINT << "FragTrap " << this->_name << " created (with name)." << Txt::RESET << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{
	std::cout << Txt::FAINT << "FragTrap " << this->_name << " created (copy)." << Txt::RESET << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << Txt::FAINT << "FragTrap " << this->_name << " destroyed." << Txt::RESET << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "FragTrap " << this->_name << " cannot request high fives, it is dead." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " requests high fives." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, FragTrap const & x)
{
	o << "[FragTrap: " << Txt::CYAN << x.getName() << Txt::RESET \
		<< ", HP: " << Txt::CYAN << x.getHitPoints() << Txt::RESET \
		<< ", EP: " << Txt::CYAN << x.getEnergyPoints() << Txt::RESET \
		<< ", AD: " << Txt::CYAN << x.getAttackDamage() << Txt::RESET \
		<< "]";
	return (o);
}
