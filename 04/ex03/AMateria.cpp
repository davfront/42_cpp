/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:29 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 10:32:03 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _type("undefined")
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[AMateria] Default constructor" << Txt::RESET << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[AMateria] Constructor with type" << Txt::RESET << std::endl;
	return ;
}

AMateria::AMateria(AMateria const & src): _type(src._type)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[AMateria] Copy constructor" << Txt::RESET << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[AMateria] Destructor" << Txt::RESET << std::endl;
	return ;
}

AMateria&	AMateria::operator=(AMateria const & rhs)
{
	this->_type = rhs._type;
	if (Txt::DEBUG)
		std::cout << Txt::FAINT << "[AMateria] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* Use of undefined materia on " << target.getName() << " *" << std::endl;
}
