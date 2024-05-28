/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:14:53 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 13:18:00 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "text_formatting.hpp"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	{
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "CONCRETE MATERIA" << Txt::RESET << std::endl << std::endl;

		Character	bob("Bob");
		
		std::cout << std::endl << Txt::CYAN << "> Ice	ice;" << Txt::RESET << std::endl;
		Ice	ice;
		std::cout << "type: " << ice.getType() << std::endl;
		std::cout << "use: "; ice.use(bob);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> Cure	cure;" << Txt::RESET << std::endl;
		Cure	cure;
		std::cout << "type: " << cure.getType() << std::endl;
		std::cout << "use: "; cure.use(bob);
		std::cout << std::endl;
				
		std::cout << std::endl << Txt::CYAN << "> AMateria*	ice2 = ice.clone();" << Txt::RESET << std::endl;
		AMateria*	ice2 = ice.clone();
		std::cout << "type: " << ice2->getType() << std::endl;
		std::cout << "use: "; ice2->use(bob);
		std::cout << std::endl;
				
		std::cout << std::endl << Txt::CYAN << "> AMateria*	cure2 = cure.clone();" << Txt::RESET << std::endl;
		AMateria*	cure2 = cure.clone();
		std::cout << "type: " << cure2->getType() << std::endl;
		std::cout << "use: "; cure2->use(bob);
		std::cout << std::endl;

		delete ice2;
		delete cure2;
	}
	{
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "MATERIA SOURCE" << Txt::RESET << std::endl << std::endl;

		std::cout << std::endl << Txt::CYAN << "> IMateriaSource*	src = new MateriaSource();" << Txt::RESET << std::endl;
		IMateriaSource*	src = new MateriaSource();
		std::cout << std::endl;
		
		AMateria*	tmp;
		
		std::cout << std::endl << Txt::CYAN << "> src->createMateria(\"ice\");" << Txt::RESET << std::endl;
		tmp = src->createMateria("ice");
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> src->learnMateria(NULL);" << Txt::RESET << std::endl;
		src->learnMateria(NULL);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> src->learnMateria(new Ice());" << Txt::RESET << std::endl;
		src->learnMateria(new Ice());
		std::cout << std::endl;
		
		for (int i = 0; i < 4; i++)
		{
			std::cout << std::endl << Txt::CYAN << "> src->learnMateria(new Cure());" << Txt::RESET << std::endl;
			src->learnMateria(new Cure());
			std::cout << std::endl;
		}
		
		std::cout << std::endl << Txt::CYAN << "> src->createMateria(\"ice\");" << Txt::RESET << std::endl;
		tmp = src->createMateria("ice");
		delete tmp;
		std::cout << std::endl;
		
		std::cout << std::endl << Txt::CYAN << "> src->createMateria(\"cure\");" << Txt::RESET << std::endl;
		tmp = src->createMateria("cure");
		delete tmp;
		std::cout << std::endl;
		
		std::cout << std::endl << Txt::CYAN << "> src->createMateria(\"fire\");" << Txt::RESET << std::endl;
		tmp = src->createMateria("fire");
		delete tmp;
		std::cout << std::endl;


		delete src;
	}
	{
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "CHARACTER" << Txt::RESET << std::endl << std::endl;
		
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "Constructors" << Txt::RESET << std::endl << std::endl;
		
		std::cout << std::endl << Txt::CYAN << "> Character	unnamed;" << Txt::RESET << std::endl;
		Character	unnamed;
		std::cout << "unnamed: " << unnamed.getName() << std::endl;
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> Character	bob(\"Bob\");" << Txt::RESET << std::endl;
		Character	bob("Bob");
		std::cout << "bob: " << bob.getName() << std::endl;
		std::cout << std::endl;
		
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "Equip & use" << Txt::RESET << std::endl << std::endl;

		std::cout << std::endl << Txt::CYAN << "> bob.equip(NULL);" << Txt::RESET << std::endl;
		bob.equip(NULL);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> AMateria*	ice = new Ice();" << Txt::RESET << std::endl;
		AMateria*	ice = new Ice();
		std::cout << std::endl << Txt::CYAN << "> bob.equip(ice);" << Txt::RESET << std::endl;
		bob.equip(ice);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> bob.use(-1, unnamed);" << Txt::RESET << std::endl;
		bob.use(-1, unnamed);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> bob.use(0, unnamed);" << Txt::RESET << std::endl;
		bob.use(0, unnamed);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> bob.use(1, unnamed);" << Txt::RESET << std::endl;
		bob.use(1, unnamed);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> bob.use(4, unnamed);" << Txt::RESET << std::endl;
		bob.use(4, unnamed);
		std::cout << std::endl;

		for(int i = 0; i < 4; i++)
		{
			std::cout << std::endl << Txt::CYAN << "> bob.equip(new Cure());" << Txt::RESET << std::endl;
			bob.equip(new Ice());
			std::cout << std::endl;
		}
		
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "Deep copy & unequip" << Txt::RESET << std::endl << std::endl;

		std::cout << std::endl << Txt::CYAN << "> Character	bob_copy(bob);" << Txt::RESET << std::endl;
		Character	bob_copy(bob);
		std::cout << std::endl;

		std::cout << std::endl << Txt::CYAN << "> bob.unequip(0);" << Txt::RESET << std::endl;
		bob.unequip(0);
		std::cout << std::endl << Txt::CYAN << "> bob.use(0, unnamed);" << Txt::RESET << std::endl;
		bob.use(0, unnamed);
		std::cout << std::endl << Txt::CYAN << "> bob_copy.use(0, unnamed);" << Txt::RESET << std::endl;
		bob_copy.use(0, unnamed);
		std::cout << std::endl;

		delete ice;
	}
	{
		std::cout << std::endl << Txt::CYAN << Txt::UNDERLINE << "MANDATORY TEST" << Txt::RESET << std::endl << std::endl;

		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*	me = new Character("me");

		AMateria*	tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter*	bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}

	return (0);
}
