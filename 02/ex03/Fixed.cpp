/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:19 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 14:21:57 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_fractional_bit_size = 8;

Fixed::Fixed(void): _value(0)
{
	return ;
}

Fixed::Fixed(int const i)
{
	this->_value = i << Fixed::_fractional_bit_size;
	return ;
}

Fixed::Fixed(float const f)
{
	this->_value = roundf(f * (1 << Fixed::_fractional_bit_size));
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	this->_value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const rhs)
{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const rhs)
{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const rhs)
{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const rhs)
{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const rhs)
{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const rhs)
{
	return (this->_value != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	++(this->_value);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	--(this->_value);
	return (temp);
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & x)
{
	return (o << x.toFloat());
}
