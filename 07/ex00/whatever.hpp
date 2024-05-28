/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:38:22 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/18 11:15:55 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T const & a, T const & b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(T const & a, T const & b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
