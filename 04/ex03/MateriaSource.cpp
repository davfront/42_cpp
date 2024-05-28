/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:43:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 10:34:56 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[MateriaSource] Default constructor" << Txt::RESET << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[MateriaSource] Copy constructor" << Txt::RESET << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[MateriaSource] Destructor" << Txt::RESET << std::endl;
	return ;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[MateriaSource] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[MateriaSource] Learn";
	
	if (!m)
	{
		if (Txt::DEBUG)
			std::cout << " -> error: unexisting masteria" << Txt::RESET << std::endl;
		return ;
	}
	if (Txt::DEBUG)
		std::cout << " " << m->getType();

	int	i = 0;
	while (this->_inventory[i] && i < SRC_INVENTORY_SIZE)
		i++;

	if (i == SRC_INVENTORY_SIZE)
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

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[MateriaSource] Create materia " << type;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			if (Txt::DEBUG)
				std::cout << Txt::RESET << std::endl;
			return (this->_inventory[i]->clone());
		}
	}
	if (Txt::DEBUG)
		std::cout << " -> error: unknown type" << Txt::RESET << std::endl;
	return (NULL);
}
