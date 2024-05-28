/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:14:53 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 10:46:21 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "text_formatting.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{

		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << 
		"CLASS CAT" 
		<< Txt::RESET << std::endl << std::endl;

		std::cout << Txt::CYAN << "> Cat  a1;" << Txt::RESET << std::endl;
		Cat	a1;
		std::cout << "a1: " << a1 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> a1.setIdea(0, \"Cheese\");" << Txt::RESET << std::endl;
		a1.setIdea(0, "Cheese");
		std::cout << Txt::CYAN << "> a1.setIdea(1, \"Bird\");" << Txt::RESET << std::endl;
		a1.setIdea(1, "Bird");
		std::cout << Txt::CYAN << "> a1.setIdea(99, \"Mouse\");" << Txt::RESET << std::endl;
		a1.setIdea(99, "Mouse");
		std::cout << "a1: " << a1 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> Cat  a2(a1);" << Txt::RESET << std::endl;
		Cat	a2(a1);
		std::cout << "a2: " << a2 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> Cat  a3;" << Txt::RESET << std::endl;
		Cat  a3;
		std::cout << Txt::CYAN << "> a3 = a1;" << Txt::RESET << std::endl;
		a3 = a1;
		std::cout << "a3: " << a3 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> a2.setIdea(0, \"Milk\");" << Txt::RESET << std::endl;
		a2.setIdea(0, "Milk");
		std::cout << Txt::CYAN << "> a3.deleteBrain();" << Txt::RESET << std::endl;
		a3.deleteBrain();
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
		std::cout << "a3: " << a3 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> a3.setIdea(0, \"Chicken\");" << Txt::RESET << std::endl;
		a3.setIdea(0, "Chicken");
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

		std::cout << Txt::CYAN << "> a1.setIdea(0, \"Cheese\");" << Txt::RESET << std::endl;
		a1.setIdea(0, "Cheese");
		std::cout << Txt::CYAN << "> a1.setIdea(1, \"Meat\");" << Txt::RESET << std::endl;
		a1.setIdea(1, "Meat");
		std::cout << Txt::CYAN << "> a1.setIdea(99, \"Bones\");" << Txt::RESET << std::endl;
		a1.setIdea(99, "Bones");
		std::cout << "a1: " << a1 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> Dog  a2(a1);" << Txt::RESET << std::endl;
		Dog	a2(a1);
		std::cout << "a2: " << a2 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> Dog  a3;" << Txt::RESET << std::endl;
		Dog  a3;
		std::cout << Txt::CYAN << "> a3 = a1;" << Txt::RESET << std::endl;
		a3 = a1;
		std::cout << "a3: " << a3 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> a2.setIdea(0, \"Sausage\");" << Txt::RESET << std::endl;
		a2.setIdea(0, "Sausage");
		std::cout << Txt::CYAN << "> a3.deleteBrain();" << Txt::RESET << std::endl;
		a3.deleteBrain();
		std::cout << "a1: " << a1 << std::endl;
		std::cout << "a2: " << a2 << std::endl;
		std::cout << "a3: " << a3 << std::endl;

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "> a3.setIdea(0, \"Ball\");" << Txt::RESET << std::endl;
		a3.setIdea(0, "Ball");
		std::cout << "a3: " << a3 << std::endl;

		std::cout<< std::endl;
	}
	{

		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << 
		"ARRAY OF CATS AND DOGS" 
		<< Txt::RESET << std::endl << std::endl;

		std::cout << Txt::CYAN << "Create array:" << Txt::RESET << std::endl << std::endl;
		Animal*	a[4];
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
			{
				std::cout << Txt::CYAN << "> a[" << i << "] = new Cat();" << Txt::RESET << std::endl;
				a[i] = new Cat();
				a[i]->setIdea(0, "Milk");
				a[i]->setIdea(1, "Mouse");
				std::cout << "*a[" << i << "]: " << *dynamic_cast<Cat*>(a[i]) << std::endl;
			}
			else
			{
				std::cout << Txt::CYAN << "> a[" << i << "] = new Dog();" << Txt::RESET << std::endl;
				a[i] = new Dog();
				a[i]->setIdea(0, "Bones");
				std::cout << "*a[" << i << "]: " << *dynamic_cast<Dog*>(a[i]) << std::endl;
			}
		}

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "Make sounds:" << Txt::RESET << std::endl << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << Txt::CYAN << "> a[" << i << "]->makeSound();" << Txt::RESET << std::endl;
			a[i]->makeSound();
		}

		std::cout<< std::endl;

		std::cout << Txt::CYAN << "Delete array:" << Txt::RESET << std::endl << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << Txt::CYAN << "> delete a[" << i << "];" << Txt::RESET << std::endl;
			delete a[i];
		}

	}
	{

		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << 
		"TEST LEAK" 
		<< Txt::RESET << std::endl << std::endl;

		const Animal*	j = new Dog();
		const Animal*	i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	return (0);
}
