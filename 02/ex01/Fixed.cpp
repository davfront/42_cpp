/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:19 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 14:20:12 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_fractional_bit_size = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << Fixed::_fractional_bit_size;
	return ;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << Fixed::_fractional_bit_size));
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::toInt(void) const
{
	return (this->_value / (1 << Fixed::_fractional_bit_size));
}

float	Fixed::toFloat(void) const
{
	return (float(this->_value) / (1 << Fixed::_fractional_bit_size));
}

std::ostream &	operator<<(std::ostream & o, Fixed const & x)
{
	return (o << x.toFloat());
}
