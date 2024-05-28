/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:11:56 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/26 22:57:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _maxSize(0)
{
	return ;
}

Span::Span(unsigned int maxSize): _maxSize(maxSize)
{
	return ;
}

Span::Span(Span const & src): _maxSize(src.getMaxSize()), _collection(src.getCollection())
{
	return ;
}

Span::~Span(void)
{
	return ;
}

Span &	Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs.getMaxSize();
		this->_collection = rhs.getCollection();
	}
	return (*this);
}

unsigned int const &	Span::getMaxSize() const
{
	return (this->_maxSize);
}

std::vector<int> const &	Span::getCollection() const
{
	return (this->_collection);
}

void	Span::addNumber(int const & value)
{
	if (this->_collection.size() < this->_maxSize)
		this->_collection.push_back(value);
	else
		throw Span::OverflowException();
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int n = std::distance(begin, end);
	if (this->_collection.size() + n > this->_maxSize)
		throw Span::OverflowException();

	for (std::vector<int>::iterator it = begin; it != end; it++)
		this->_collection.push_back(*it);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int> const & v = this->_collection;
	if (v.size() < 2)
		throw Span::NotEnoughElementsException();

	std::vector<int> sortedList = v;
	std::sort(sortedList.begin(), sortedList.end());
	
	std::vector<int>::const_iterator begin = sortedList.begin();
	std::vector<int>::const_iterator end = sortedList.end();
	std::vector<int>::const_iterator it;
	std::vector<int> spans;
	for (it = begin; it != end - 1; it++) {
		spans.push_back(*(it + 1) - *it);
		// std::cout << *(it + 1) << " - " << *it << " | ";
	}
	return (*std::min_element(spans.begin(), spans.end()));
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int> const & v = this->_collection;
	if (v.size() < 2)
		throw Span::NotEnoughElementsException();

	unsigned int maxEl = *std::max_element(v.begin(), v.end());
	unsigned int minEl = *std::min_element(v.begin(), v.end());
	return (maxEl - minEl);
}

std::ostream &	operator<<(std::ostream & o, Span const & x)
{
	std::vector<int> const &	v = x.getCollection();

	o << "{";
	o << "maxSize: " << x.getMaxSize() << ", ";
	o << "size: " << v.size() << ", ";
	o << "collection: {";
	std::vector<int>::const_iterator begin = v.begin();
	std::vector<int>::const_iterator end = v.end();
	for (std::vector<int>::const_iterator it = begin; it != end; it++)
		o << *it << ((it != end - 1) ? ", " : "");
	o << "}}";
	return (o);
}
