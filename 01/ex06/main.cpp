/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:29:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/23 17:18:36 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "[USAGE] " << argv[0] << " <DEBUG | INFO | WARNING | ERROR>" << std::endl;
		return (1);
	}
	
	if (!harl.setFilter(argv[1]))
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	harl.complain("UNKNOWN");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	
	return (0);
}
