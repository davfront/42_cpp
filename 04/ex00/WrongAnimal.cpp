/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:29 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 14:22:48 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("Undefined")
{
	std::cout << Txt::FAINT << "[WrongAnimal] Default constructor (Undefined type)" << Txt::RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const std::string& type): _type(type)
{
	std::cout << Txt::FAINT << "[WrongAnimal] Constructor with type (" << _type << ")" << Txt::RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src): _type(src._type)
{
	std::cout << Txt::FAINT << "[WrongAnimal] Copy (" << _type << ")" << Txt::RESET << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << Txt::FAINT << "[WrongAnimal] Destructor (type: " << _type << ")" << Txt::RESET << std::endl;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << Txt::FAINT << "[WrongAnimal] Copy assignment operator (type: " << _type << ")" << Txt::RESET << std::endl;
	this->_type = rhs._type;
	return (*this);
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Um..." << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const WrongAnimal& x)
{
	o << "[WrongAnimal: " << x.getType() << "]";
	return (o);
}
