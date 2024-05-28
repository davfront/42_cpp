/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:48:56 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 22:33:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << Txt::FAINT << "[Brain] Default constructor" << Txt::RESET << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		this->_ideas[i] = "";
	return ;
}

Brain::Brain(const Brain& src)
{
	std::cout << Txt::FAINT << "[Brain] Copy" << Txt::RESET << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		this->_ideas[i] = src._ideas[i];
	return ;
}

Brain::~Brain(void)
{
	std::cout << Txt::FAINT << "[Brain] Destructor" << Txt::RESET << std::endl;
	return ;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << Txt::FAINT << "[Brain] Copy assignment operator" << Txt::RESET << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

std::string	Brain::getIdea(const int& index) const
{
	if (index < 0 || index >= IDEAS_SIZE)
		return ("");
	return (this->_ideas[index]);
}

void	Brain::setIdea(const int& index, const std::string& idea)
{
	if (index < 0 || index >= IDEAS_SIZE)
		return ;
	this->_ideas[index] = idea;
}

std::ostream&	operator<<(std::ostream& o, const Brain& x)
{
	bool	print_started = false;

	std::cout << "[";
	for (int i = 0; i < IDEAS_SIZE; i++)
	{
		if (x.getIdea(i) != "")
		{
			std::cout << (print_started ? ", " : "");
			std::cout << i << ": " << x.getIdea(i);
			print_started = true;
		}
	}
	std::cout << "]";
	return (o);
}
