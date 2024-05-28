/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 20:09:19 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "Brain.hpp"

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

		virtual const Brain*	getBrain(void) const = 0;
		virtual void			setBrain(Brain* brain_p) = 0;
		virtual void			deleteBrain(void) = 0;

		virtual std::string		getIdea(const int& index) const = 0;
		virtual void			setIdea(const int& index, const std::string& idea) = 0;

		virtual void			makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const Animal& x);

#endif
