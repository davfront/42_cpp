/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:14:53 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 15:44:35 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "text_formatting.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << \
		"CLASS ANIMAL" \
		<< Txt::RESET << std::endl << std::endl;
		
		std::cout << Txt::CYAN << "> Animal  a1;" << Txt::RESET << std::endl;
		Animal	a1;
		std::cout << "a1: " << a1 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> Animal  a2(\"Koala\");" << Txt::RESET << std::endl;
		Animal	a2("Koala");
		std::cout << "a2: " << a2 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> Animal  a3(a2);" << Txt::RESET << std::endl;
		Animal  a3(a2);
		std::cout << "a3: " << a3 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> a3 = a1;" << Txt::RESET << std::endl;
		a3 = a1;
		std::cout << "a3: " << a3 << std::endl;
		
		std::cout<< std::endl;
	}
	{
		
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << 
		"CLASS CAT" 
		<< Txt::RESET << std::endl << std::endl;
		
		std::cout << Txt::CYAN << "> Cat  a1;" << Txt::RESET << std::endl;
		Cat	a1;
		std::cout << "a1: " << a1 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> Cat  a2;" << Txt::RESET << std::endl;
		Cat	a2;
		std::cout << "a2: " << a2 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> Cat  a3(a1);" << Txt::RESET << std::endl;
		Cat  a3(a1);
		std::cout << "a3: " << a3 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> a3 = a2;" << Txt::RESET << std::endl;
		a3 = a2;
		std::cout << "a3: " << a3 << std::endl;
		
		std::cout<< std::endl;
	}
	{
		
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << 
		"CLASS DOG" 
		<< Txt::RESET << std::endl << std::endl;
		
		std::cout << Txt::CYAN << "> Dog  a1;" << Txt::RESET << std::endl;
		Dog	a1;
		std::cout << "a1: " << a1 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> Dog  a2;" << Txt::RESET << std::endl;
		Dog	a2;
		std::cout << "a2: " << a2 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> Dog  a3(a1);" << Txt::RESET << std::endl;
		Dog  a3(a1);
		std::cout << "a3: " << a3 << std::endl;
		
		std::cout<< std::endl;
		
		std::cout << Txt::CYAN << "> a3 = a2;" << Txt::RESET << std::endl;
		a3 = a2;
		std::cout << "a3: " << a3 << std::endl;
		
		std::cout<< std::endl;
	}
	{
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << \
		"SUB-TYPING POLYMORPHISM" \
		<< Txt::RESET << std::endl << std::endl;
		
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << \
		"WRONG SUB-TYPING POLYMORPHISM" \
		<< Txt::RESET << std::endl << std::endl;

		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}
	return (0);
}
