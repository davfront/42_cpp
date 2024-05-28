/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:34:27 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 11:56:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Cure] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Cure::Cure(Cure const & src): AMateria(src)
{
	this->_type = "cure";
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Cure] Copy constructor" << Txt::RESET << std::endl;
	return ;
}

Cure::~Cure(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Cure] Destructor" << Txt::RESET << std::endl;
	return ;
}

Cure&	Cure::operator=(Cure const & rhs)
{
	AMateria::operator=(rhs);
	this->_type = "cure";
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Cure] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[Cure] Clone" << Txt::RESET << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
