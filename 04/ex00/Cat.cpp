/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:43 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << Txt::FAINT << "[Cat] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Cat::Cat(const Cat& src): Animal(src)
{
	this->_type = "Cat";
	std::cout << Txt::FAINT << "[Cat] Copy" << Txt::RESET << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << Txt::FAINT << "[Cat] Destructor" << Txt::RESET << std::endl;
	return ;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
	this->_type = "Cat";
	std::cout << Txt::FAINT << "[Cat] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Cat& x)
{
	o << "[" << x.getType() << "]";
	return (o);
}
