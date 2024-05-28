/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:32 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 01:16:00 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "text_formatting.hpp"

int	main(void)
{
	
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> FragTrap  unnamed;" << Txt::RESET << std::endl;
	FragTrap	unnamed;
	std::cout << "unnamed: " << unnamed << std::endl;
	
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> FragTrap  brad(\"Brad\")" << Txt::RESET << std::endl;
	FragTrap	brad("Brad");
	std::cout << "brad: " << brad << std::endl;
	
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> FragTrap  brad_copy(brad);" << Txt::RESET << std::endl;
	FragTrap	brad_copy(brad);
	std::cout << "brad_copy: " << brad_copy << std::endl;
	
	std::cout<< std::endl;

	std::cout << Txt::PURPLE << "> unnamed.attack(\"John\");" << Txt::RESET << std::endl;
	unnamed.attack("John");
	std::cout << unnamed << std::endl;
		
	std::cout<< std::endl;
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << Txt::PURPLE << "> brad.takeDamage(49);" << Txt::RESET << std::endl;
		brad.takeDamage(49);
		std::cout << brad << std::endl;
		std::cout << Txt::PURPLE << "> brad.beRepaired(1);" << Txt::RESET << std::endl;
		brad.beRepaired(1);
		std::cout << brad << std::endl;
	}
		
	std::cout<< std::endl;

	
	std::cout << Txt::PURPLE << "> brad.attack(\"John\");" << Txt::RESET << std::endl;
	brad.attack("John");
	std::cout << brad << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> unnamed.highFivesGuys();" << Txt::RESET << std::endl;
	unnamed.highFivesGuys();
	std::cout << unnamed << std::endl;
		
	std::cout<< std::endl;

	std::cout << Txt::PURPLE << "> brad.highFivesGuys();" << Txt::RESET << std::endl;
	brad.highFivesGuys();
	std::cout << brad << std::endl;
		
	std::cout<< std::endl;
	
	return (0);
}
