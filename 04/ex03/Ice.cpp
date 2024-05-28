/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:50:19 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 11:56:41 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Ice] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Ice::Ice(Ice const & src): AMateria(src)
{
	this->_type = "ice";
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Ice] Copy constructor" << Txt::RESET << std::endl;
	return ;
}

Ice::~Ice(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Ice] Destructor" << Txt::RESET << std::endl;
	return ;
}

Ice&	Ice::operator=(Ice const & rhs)
{
	AMateria::operator=(rhs);
	this->_type = "ice";
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Ice] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Ice] Clone" << Txt::RESET << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
