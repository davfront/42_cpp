/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:37:05 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 10:33:40 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("Unnamed")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Character::Character(std::string const & name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Constructor with parameters" << Txt::RESET << std::endl;
	return ;
}

Character::Character(Character const & src): _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Copy constructor" << Txt::RESET << std::endl;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Destructor" << Txt::RESET << std::endl;
	return ;
}

Character&	Character::operator=(Character const & rhs)
{
	this->_name = rhs._name;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Equip";
	
	if (!m)
	{
		if (Txt::DEBUG)
			std::cout << " -> error: unexisting materia" << Txt::RESET << std::endl;
		return ;
	}
	if (Txt::DEBUG)
		std::cout << " " << m->getType();

	int	i = 0;
	while (this->_inventory[i] && i < INVENTORY_SIZE)
		i++;

	if (i == INVENTORY_SIZE)
	{
		if (Txt::DEBUG)
			std::cout << " -> error: full inventory" << Txt::RESET << std::endl;
		delete m;
		return ;
	}
	this->_inventory[i] = m;
	if (Txt::DEBUG)
		std::cout << Txt::RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character: " << this->_name << "] Unequip slot `" << idx << "` materia";
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
	{
		if (Txt::DEBUG)
			std::cout << " -> error: invalid index" << Txt::RESET << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	if (Txt::DEBUG)
		std::cout << Txt::RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Character] Use slot `" << idx << "` materia";
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
	{
		if (Txt::DEBUG)
			std::cout << " -> error: invalid index" << Txt::RESET << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		if (Txt::DEBUG)
			std::cout << " -> error: no materia found" << Txt::RESET << std::endl;
		return ;
	}
	if (Txt::DEBUG)
		std::cout << " " << this->_inventory[idx]->getType() << Txt::RESET << std::endl;
	this->_inventory[idx]->use(target);
}
