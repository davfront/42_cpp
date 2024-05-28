/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:16 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 14:08:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:

		Fixed(void);
		Fixed(int const i);
		Fixed(float const f);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed&	operator=(Fixed const & rhs);

		bool	operator>(Fixed const rhs);
		bool	operator<(Fixed const rhs);
		bool	operator>=(Fixed const rhs);
		bool	operator<=(Fixed const rhs);
		bool	operator==(Fixed const rhs);
		bool	operator!=(Fixed const rhs);

		Fixed	operator+(Fixed const rhs);
		Fixed	operator-(Fixed const rhs);
		Fixed	operator*(Fixed const rhs);
		Fixed	operator/(Fixed const rhs);
		
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		
		static Fixed&			min(Fixed& a, Fixed& b);
		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed&			max(Fixed& a, Fixed& b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);

	private:

		static int const	_fractional_bit_size;

		int		_value;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & x);

#endif
