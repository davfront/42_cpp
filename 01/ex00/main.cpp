/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:03:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/15 10:30:40 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie*	zombie1_p;

	zombie1_p = newZombie("zombie1");
	(*zombie1_p).announce();
	randomChump("zombie2");
	delete zombie1_p;

	return (0);
}
