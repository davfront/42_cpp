/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:15:44 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/22 15:22:55 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	int			i;
	int			j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			argv[i][j] = std::toupper(argv[i][j]);
			j++;
		}
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}
