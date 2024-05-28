/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:29 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("Undefined")
{
	std::cout << Txt::FAINT << "[AAnimal] Default constructor" << Txt::RESET << std::endl;
	return ;
}

AAnimal::AAnimal(const std::string& type): _type(type)
{
	std::cout << Txt::FAINT << "[AAnimal] Constructor with type" << Txt::RESET << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal& src): _type(src._type)
{
	std::cout << Txt::FAINT << "[AAnimal] Copy " << Txt::RESET << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << Txt::FAINT << "[AAnimal] Destructor" << Txt::RESET << std::endl;
	return ;
}

AAnimal&	AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << Txt::FAINT << "[AAnimal] Copy assignment operator" << Txt::RESET << std::endl;
	this->_type = rhs._type;
	return (*this);
}

const std::string&	AAnimal::getType(void) const
{
	return (this->_type);
}

std::ostream&	operator<<(std::ostream& o, const AAnimal& x)
{
	o << "[AAnimal: " << x.getType() << "]";
	return (o);
}
