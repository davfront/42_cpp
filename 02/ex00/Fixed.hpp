/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:16 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 12:48:44 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed&	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		static int const	_fractional_bit_size;

		int		_value;

};

#endif
