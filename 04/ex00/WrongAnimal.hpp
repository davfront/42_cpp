/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 18:21:47 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include "text_formatting.hpp"

class WrongAnimal {
	
	protected:

		std::string		_type;

	public:

		WrongAnimal(void);
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal(void);
		
		WrongAnimal&	operator=(const WrongAnimal& rhs);

		const std::string&	getType(void) const;

		void	makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const WrongAnimal& x);

#endif
