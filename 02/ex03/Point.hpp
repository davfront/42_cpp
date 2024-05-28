/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:32:48 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 15:50:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	public:

		Point(void);
		Point(float const fx, float const fy);
		Point(Point const & src);
		~Point(void);

		Point&	operator=(Point const & rhs);
		Point	operator-(Point const rhs);
		
		Fixed	getX(void) const;
		void	setX(Fixed const x);
		Fixed	getY(void) const;
		void	setY(Fixed const y);

		static float	dot(Point const a, Point const b);

	private:

		Fixed	_x;
		Fixed	_y;

};

std::ostream &	operator<<(std::ostream & o, Point const & p);

#endif
