/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:14:44 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/28 17:48:37 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <cstdlib>
# include <sstream>
# include <ctime>
# include <iomanip>

class PmergeMe {

	private:

		std::vector<unsigned int>	_args;
		
		static unsigned int	_parseArg(std::string arg);
		
		template <typename T>
		static void	sort(T & arr);

		template <typename T>
		static void	sortRange(typename T::iterator left, typename T::iterator right);

		template <typename T>
		static void	mergeInPlaceRanges(typename T::iterator left, typename T::iterator middle, typename T::iterator right);

	public:

		PmergeMe(void);
		PmergeMe(int size, char** args);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);

		PmergeMe &	operator=(PmergeMe const & rhs);

		std::vector<unsigned int> const &	getArgs(void) const;
		
		template<typename T>
		static std::string	stringify(T list);
		
		template<typename T>
		static std::string	stringify(T list, unsigned int n);
		
		void	run(void) const;

};

std::ostream &	operator<<(std::ostream & o, PmergeMe const & x);

#endif
