/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:43 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 14:18:54 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << Txt::FAINT << "[WrongCat] Default constructor" << Txt::RESET << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src)
{
	this->_type = "WrongCat";
	std::cout << Txt::FAINT << "[WrongCat] Copy" << Txt::RESET << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << Txt::FAINT << "[WrongCat] Destructor" << Txt::RESET << std::endl;
	return ;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	WrongAnimal::operator=(rhs);
	this->_type = "WrongCat";
	std::cout << Txt::FAINT << "[WrongCat] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const WrongCat& x)
{
	o << "[" << x.getType() << "]";
	return (o);
}
