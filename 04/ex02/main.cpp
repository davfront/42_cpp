/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:14:53 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 20:29:34 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "text_formatting.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// const AAnimal	meta; // not allowed

	std::cout<< std::endl;

	std::cout << Txt::CYAN << "> const AAnimal*	j = new Dog();" << Txt::RESET << std::endl;
	const AAnimal*	j = new Dog();
	std::cout << "*j: " << *j << std::endl;

	std::cout<< std::endl;

	std::cout << Txt::CYAN << "> const AAnimal*	i = new Cat();" << Txt::RESET << std::endl;
	const AAnimal*	i = new Cat();
	std::cout << "*i: " << *i << std::endl;

	std::cout<< std::endl;

	std::cout << Txt::CYAN << "> delete j;" << Txt::RESET << std::endl;
	delete j;

	std::cout<< std::endl;

	std::cout << Txt::CYAN << "> delete i;" << Txt::RESET << std::endl;
	delete i;

	return (0);
}
