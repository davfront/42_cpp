/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:52:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/18 11:59:49 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void	iter(T* arr, size_t len, void (*f)(T &))
{
	for (size_t i = 0; i < len; i++) {
		(*f)(arr[i]);
	}
}

template <typename T>
void	iter(T* arr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++) {
		(*f)(arr[i]);
	}
}

#endif
