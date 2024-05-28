/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:29 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Undefined")
{
	std::cout << Txt::FAINT << "[Animal] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Animal::Animal(const std::string& type): _type(type)
{
	std::cout << Txt::FAINT << "[Animal] Constructor with type" << Txt::RESET << std::endl;
	return ;
}

Animal::Animal(const Animal& src): _type(src._type)
{
	std::cout << Txt::FAINT << "[Animal] Copy " << Txt::RESET << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << Txt::FAINT << "[Animal] Destructor" << Txt::RESET << std::endl;
	return ;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	std::cout << Txt::FAINT << "[Animal] Copy assignment operator" << Txt::RESET << std::endl;
	this->_type = rhs._type;
	return (*this);
}

const std::string&	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Um..." << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Animal& x)
{
	o << "[Animal: " << x.getType() << "]";
	return (o);
}
