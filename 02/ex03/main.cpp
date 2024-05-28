/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:48:14 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 15:56:32 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main(void )
{
	Point	a(0.1, -0.1);
	Point	b(0, 5.2);
	Point	c(5.3, 0);
	Point	p(2.55, 2.5);
	
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout<< std::endl;
	std::cout << "P = " << p << std::endl;
	std::cout<< std::endl;
	std::cout << "Is the P inside the triangle ABC? ";
	if (bsp(a, b, c, p))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	return 0;
}
