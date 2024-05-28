/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:32 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 03:27:24 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"
#include "text_formatting.hpp"

int	main(void)
{
	
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> ClapTrap  clap(\"Clap\");" << Txt::RESET << std::endl;
	ClapTrap	clap("Clap");
	std::cout << "clap: " << clap << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> ScavTrap  scav(\"Scav\");" << Txt::RESET << std::endl;
	ScavTrap	scav("Scav");
	std::cout << "scav: " << scav << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> FragTrap  frag(\"Frag\");" << Txt::RESET << std::endl;
	FragTrap	frag("Frag");
	std::cout << "frag: " << frag << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> DiamondTrap  diamond(\"Diamond\");" << Txt::RESET << std::endl;
	DiamondTrap	diamond("Diamond");
	std::cout << "diamond: " << diamond << std::endl;
	diamond.whoAmI();
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> diamond.attack(\"John\");" << Txt::RESET << std::endl;
	diamond.attack("John");
	std::cout << diamond << std::endl;
		
	std::cout<< std::endl;

	std::cout << Txt::PURPLE << "> diamond.takeDamage(10);" << Txt::RESET << std::endl;
	diamond.takeDamage(10);
	std::cout << diamond << std::endl;
		
	std::cout<< std::endl;

	std::cout << Txt::PURPLE << "> diamond.beRepaired(5);" << Txt::RESET << std::endl;
	diamond.beRepaired(5);
	std::cout << diamond << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> diamond.guardGate();" << Txt::RESET << std::endl;
	diamond.guardGate();
	std::cout << diamond << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> diamond.highFivesGuys();" << Txt::RESET << std::endl;
	diamond.highFivesGuys();
	std::cout << diamond << std::endl;
		
	std::cout<< std::endl;
	
	std::cout << Txt::PURPLE << "> diamond.whoAmI();" << Txt::RESET << std::endl;
	diamond.whoAmI();
	std::cout << diamond << std::endl;
		
	std::cout<< std::endl;
	
	return (0);
}
