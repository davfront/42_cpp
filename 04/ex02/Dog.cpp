/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:06:43 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): AAnimal("Dog"), _brain(new Brain())
{
	std::cout << Txt::FAINT << "[Dog] Default constructor" << Txt::RESET << std::endl;
	return ;
}

Dog::Dog(const Dog& src): AAnimal(src)
{
	this->_type = "Dog";
	if (src._brain)
		this->_brain = new Brain(*src._brain);
	else
		this->_brain = NULL;
	std::cout << Txt::FAINT << "[Dog] Copy" << Txt::RESET << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << Txt::FAINT << "[Dog] Destructor" << Txt::RESET << std::endl;
	return ;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	AAnimal::operator=(rhs);
	this->_type = "Dog";
	if (!rhs._brain)
		this->deleteBrain();
	else if (!this->_brain)
		this->_brain = new Brain(*rhs._brain);
	else
		*this->_brain = *rhs._brain;
	std::cout << Txt::FAINT << "[Dog] Copy assignment operator" << Txt::RESET << std::endl;
	return (*this);
}

const Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::setBrain(Brain* brain_p)
{
	this->_brain = brain_p;
	std::cout << Txt::FAINT << "[Dog] Set brain" << Txt::RESET << std::endl;
}

void	Dog::deleteBrain(void)
{
	std::cout << Txt::FAINT << "[Dog] Delete brain" << Txt::RESET << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}
		
std::string	Dog::getIdea(const int& index) const
{
	if (!this->_brain)
		return ("");
	else
		return (this->_brain->getIdea(index));
}

void	Dog::setIdea(const int& index, const std::string& idea)
{
	std::cout << Txt::FAINT << "[Dog] Set idea" << Txt::RESET << std::endl;
	if (!this->_brain)
		this->_brain = new Brain();
	this->_brain->setIdea(index, idea);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Dog& x)
{
	if (x.getBrain())
		o << "[" << x.getType() << ", " << *x.getBrain() << "]";
	else
		o << "[" << x.getType() << ", null]";
	return (o);
}
