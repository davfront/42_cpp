/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:43 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << Txt::FAINT << "[Dog] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Dog::Dog(const Dog& src): Animal(src)
{
	this->_type = "Dog";
	std::cout << Txt::FAINT << "[Dog] Copy" << Txt::RESET << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << Txt::FAINT << "[Dog] Destructor" << Txt::RESET << std::endl;
	return ;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	this->_type = "Dog";
	std::cout << Txt::FAINT << "[Dog] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Dog& x)
{
	o << "[" << x.getType() << "]";
	return (o);
}
