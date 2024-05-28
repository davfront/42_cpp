/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:02:41 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/18 11:58:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void	print(T const & i)
{
	std::cout << " " << i << " ";
}

template <typename T>
void	negate(T & i)
{
	i = -i;
}

int	main(void)
{
	{
		int	arr_int[] = { 9, 53, -8, 3, 0 };

		std::cout << "arr_int: ";
		iter(arr_int, 5, print<int>);
		std::cout << std::endl;

		iter(arr_int, 5, negate<int>);
		std::cout << "arr_int: ";
		iter(arr_int, 5, print<int>);
		std::cout << std::endl;
	}
	{
		double	arr_double[] = { -7.8, 1234.5, 10 };

		std::cout << "arr_double: ";
		iter(arr_double, 3, print<double>);
		std::cout << std::endl;

		iter(arr_double, 3, negate<double>);
		std::cout << "arr_double: ";
		iter(arr_double, 3, print<double>);
		std::cout << std::endl;
	}

	return (0);
}
