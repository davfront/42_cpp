/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:53:44 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/26 22:26:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <limits>
# include <iostream>

class Span {

	private:

		unsigned int		_maxSize;
		std::vector<int>	_collection;

	public:

		Span(void);
		Span(unsigned int maxSize);
		Span(Span const & src);
		~Span(void);

		Span &	operator=(Span const & rhs);

		unsigned int const &		getMaxSize() const;
		std::vector<int> const &	getCollection() const;

		void			addNumber(int const & value);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class OverflowException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Maximum size exceeded";
				}
		};

		class NotEnoughElementsException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough elements";
				}
		};

};

std::ostream &	operator<<(std::ostream & o, Span const & x);

#endif
