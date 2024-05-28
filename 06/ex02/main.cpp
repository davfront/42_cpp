/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:03:51 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/26 12:14:14 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

Base*	generate(void)
{
	std::srand(std::time(NULL));
	int	i = std::rand() % 3;

	switch (i) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Class not found";
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return ;
	} catch(std::exception &) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return ;
	} catch(std::exception &) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return ;
	} catch(std::exception &) {}

	std::cout << "Class not found";
}

int	main(void)
{

	Base*	ptr = generate();
	Base&	ref = *ptr;

	std::cout << "class pointed by ptr: ";
	identify(ptr);
	std::cout << std::endl;

	std::cout << "class pointed by ref: ";
	identify(ref);
	std::cout << std::endl;

	delete ptr;

	return (0);
}
