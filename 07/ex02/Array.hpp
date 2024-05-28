/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:35:44 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/18 16:28:02 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
	
	private:

		unsigned int	_size;
		T*				_array;

	public:

		Array(void);
		Array(unsigned int n);
		Array(Array const & src);
		~Array(void);

		Array &		operator=(Array const & rhs);
		T &			operator[](unsigned int index);
		T const &	operator[](unsigned int index) const;

		unsigned int const &	size(void) const;

		class	OutOfBoundsIndexException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "The index is out of bounds";
				};
		};

};

template <typename T>
std::ostream &	operator<<(std::ostream & o, Array<T> const & rhs);

# include "Array.tpp"

#endif
