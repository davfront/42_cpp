/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:48:54 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 18:21:59 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "text_formatting.hpp"

# define IDEAS_SIZE	100

class Brain {
	
	private:

		std::string		_ideas[IDEAS_SIZE];

	public:

		Brain(void);
		Brain(const Brain& src);
		virtual ~Brain(void);
		
		Brain&	operator=(const Brain& rhs);

		std::string	getIdea(const int& index) const;
		void		setIdea(const int& index, const std::string& idea);

};

std::ostream&	operator<<(std::ostream& o, const Brain& x);

#endif
