/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:32:45 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 15:51:04 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
	return ;
}

Point::Point(float const fx, float const fy): _x(fx), _y(fy)
{
	return ;
}

Point::Point(Point const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	return ;
}

Point::~Point(void)
{
	return ;
}

Point&	Point::operator=(Point const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

Point	Point::operator-(Point const rhs)
{
	Point	p;

	p.setX(this->_x - rhs.getX());
	p.setY(this->_y - rhs.getY());
	return (p);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

void	Point::setX(Fixed const x)
{
	this->_x = x;
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

void	Point::setY(Fixed const y)
{
	this->_y = y;
}

float	Point::dot(Point const a, Point const b)
{
	return (a.getX().toFloat() * b.getX().toFloat() + a.getY().toFloat() * b.getY().toFloat());
}

std::ostream &	operator<<(std::ostream & o, Point const & p)
{
	return (o << "(" << p.getX() << ", " << p.getY() << ")");
}
