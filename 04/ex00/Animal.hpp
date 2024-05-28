/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 18:21:20 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "text_formatting.hpp"

class Animal {
	
	protected:

		std::string		_type;

	public:

		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& src);
		virtual ~Animal(void);
		
		Animal&	operator=(const Animal& rhs);

		const std::string&	getType(void) const;

		virtual void	makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const Animal& x);

#endif
