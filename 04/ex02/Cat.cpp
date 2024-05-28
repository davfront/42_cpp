/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:43 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat"), _brain(new Brain())
{
	std::cout << Txt::FAINT << "[Cat] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Cat::Cat(const Cat& src): AAnimal(src)
{
	this->_type = "Cat";
	if (src._brain)
		this->_brain = new Brain(*src._brain);
	else
		this->_brain = NULL;
	std::cout << Txt::FAINT << "[Cat] Copy" << Txt::RESET << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << Txt::FAINT << "[Cat] Destructor" << Txt::RESET << std::endl;
	return ;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	AAnimal::operator=(rhs);
	this->_type = "Cat";
	if (!rhs._brain)
		this->deleteBrain();
	else if (!this->_brain)
		this->_brain = new Brain(*rhs._brain);
	else
		*this->_brain = *rhs._brain;
	std::cout << Txt::FAINT << "[Cat] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

const Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::setBrain(Brain* brain_p)
{
	this->_brain = brain_p;
	std::cout << Txt::FAINT << "[Cat] Set brain" << Txt::RESET << std::endl;
}

void	Cat::deleteBrain(void)
{
	std::cout << Txt::FAINT << "[Cat] Delete brain" << Txt::RESET << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}
		
std::string	Cat::getIdea(const int& index) const
{
	if (!this->_brain)
		return ("");
	else
		return (this->_brain->getIdea(index));
}

void	Cat::setIdea(const int& index, const std::string& idea)
{
	std::cout << Txt::FAINT << "[Cat] Set idea" << Txt::RESET << std::endl;
	if (!this->_brain)
		this->_brain = new Brain();
	this->_brain->setIdea(index, idea);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Cat& x)
{
	if (x.getBrain())
		o << "[" << x.getType() << ", " << *x.getBrain() << "]";
	else
		o << "[" << x.getType() << ", null]";
	return (o);
}
