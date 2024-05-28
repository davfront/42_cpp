/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:14:41 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/28 18:08:48 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Canonical form
// ------------------------------------------------------------------------

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(int size, char** args)
{
	for (int i = 0; i < size; i++) {
		unsigned int value = PmergeMe::_parseArg(args[i]);
		this->_args.push_back(value);
	}
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src): _args(src.getArgs())
{
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe &	PmergeMe::operator=(PmergeMe const & rhs)
{
	this->_args = rhs.getArgs();
	return (*this);
}

std::vector<unsigned int> const &	PmergeMe::getArgs(void) const
{
	return (this->_args);
}


std::ostream &	operator<<(std::ostream & o, PmergeMe const & x)
{
	o << PmergeMe::stringify(x.getArgs());
	return (o);
}

// Private functions
// ------------------------------------------------------------------------

unsigned int	PmergeMe::_parseArg(std::string arg)
{
	if (arg.empty())
		throw std::runtime_error(std::string("Invalid argument: `") + arg + "` is not a positive integer");

	for (size_t i = 0; i < arg.size(); i++) {
		if (!isdigit(arg[i]))
			throw std::runtime_error(std::string("Invalid argument: `") + arg + "` is not a positive integer");
	}
		
	double value = atof(arg.c_str());
	if (value > std::numeric_limits<unsigned int>::max())
		throw std::runtime_error(std::string("Invalid argument: `") + arg + "` is a too large positive integer");

	return(static_cast<unsigned int>(value));

}

template <typename T>
void	PmergeMe::sort(T & arr)
{
	if (arr.size() < 2)
		return ;

	PmergeMe::sortRange<T>(arr.begin(), arr.end() - 1);
}

template <typename T>
void	PmergeMe::sortRange(
	typename T::iterator left,
	typename T::iterator right
)
{
	if (left == right)
		return ;

	typename T::iterator middle = left + (right - left) / 2;
	PmergeMe::sortRange<T>(left, middle);
	PmergeMe::sortRange<T>(middle + 1, right);
	PmergeMe::mergeInPlaceRanges<T>(left, middle, right);
}

template <typename T>
void	PmergeMe::mergeInPlaceRanges(
	typename T::iterator left,
	typename T::iterator middle,
	typename T::iterator right
)
{
	// copy both subranges in temporary collections
	T leftCopy(left, middle + 1);
	T rightCopy(middle + 1, right + 1);

	// Merge the temporary collections back into the original range
	typename T::iterator leftIt = leftCopy.begin();
	typename T::iterator leftEndIt = leftCopy.end();
	typename T::iterator rightIt = rightCopy.begin();
	typename T::iterator rightEndIt = rightCopy.end();
	typename T::iterator destIt = left;

	while (leftIt != leftEndIt && rightIt != rightEndIt) {
		if (*leftIt <= *rightIt) {
			*destIt = *leftIt;
			leftIt++;
		} else {
			*destIt = *rightIt;
			rightIt++;
		}
		destIt++;
	}

	// Copy the remaining elements of leftCopy
	while (leftIt != leftEndIt) {
		*destIt = *leftIt;
		leftIt++;
		destIt++;
	}

	// Copy the remaining elements of rightCopy
	while (rightIt != rightEndIt) {
		*destIt = *rightIt;
		rightIt++;
		destIt++;
	}
}

// Public functions
// ------------------------------------------------------------------------

template<typename T>
std::string	PmergeMe::stringify(T list)
{
	std::ostringstream oss;
	typename T::const_iterator	begin = list.begin();
	typename T::const_iterator	end = list.end();
	typename T::const_iterator	it;
	for (it = begin; it != end; it++)
		oss << *it << " ";
	return (oss.str());
}


template<typename T>
std::string	PmergeMe::stringify(T list, unsigned int n)
{
	if (n >= list.size())
		return (PmergeMe::stringify(list));

	std::ostringstream oss;
	typename T::const_iterator	begin = list.begin();
	typename T::const_iterator	it;
	for (it = begin; it != (begin + n); it++)
		oss << *it << " ";
	oss << "[...]";
	return (oss.str());
}

void	PmergeMe::run(void) const
{
	clock_t startTime;
	unsigned int listMaxSize = 10;
	std::cout << std::fixed << std::setprecision(0);

	// vector
	std::vector<unsigned int> vecList(this->_args.begin(), this->_args.end());

	startTime = clock();
	std::vector<unsigned int> vecSortedList = vecList;
	PmergeMe::sort(vecSortedList);
	double vecTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC * 1e6;
	
	// std::cout << "== Vector ==" << std::endl;
	std::cout << "Before: " << PmergeMe::stringify(vecList, listMaxSize) << std::endl;
	std::cout << "After:  " << PmergeMe::stringify(vecSortedList, listMaxSize) << std::endl;
	std::cout << "Time to process a range of " <<  vecList.size() << " elements with std::vector : " << vecTime << "us" << std::endl;

	// deque
	std::deque<unsigned int> deqList(this->_args.begin(), this->_args.end());
	
	startTime = clock();
	std::deque<unsigned int> deqSortedList = deqList;
	PmergeMe::sort(deqSortedList);
	double deqTime = static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC * 1e6;
	
	// std::cout << std::endl << std::fixed << std::setprecision(0);
	// std::cout << "== Deque ==" << std::endl;
	// std::cout << "Before: " << PmergeMe::stringify(deqList, listMaxSize) << std::endl;
	// std::cout << "After:  " << PmergeMe::stringify(deqSortedList, listMaxSize) << std::endl;
	std::cout << "Time to process a range of " <<  deqList.size() << " elements with std::deque : " << deqTime << "us" << std::endl;
}
