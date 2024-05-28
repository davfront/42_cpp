/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:03:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/15 11:46:57 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int			i;
	int const	N1 = 2;
	Zombie*		horde1 = zombieHorde(N1, "horde1");
	int const	N2 = 3;
	Zombie*		horde2 = zombieHorde(N2, "horde2");

	std::cout << std::endl;
	i = 0;
	while (i < N1)
	{
		horde1[i].announce();
		i++;
	}

	std::cout << std::endl;
	i = 0;
	while (i < N2)
	{
		horde2[i].announce();
		i++;
	}

	std::cout << std::endl;
	delete [] horde1;

	std::cout << std::endl;
	delete [] horde2;

	std::cout << std::endl;
	return (0);
}
