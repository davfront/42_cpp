/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:01 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 14:32:03 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include "text_formatting.hpp"

class Dog: public Animal
{

	public:

		Dog(void);
		Dog(const Dog& src);
		virtual ~Dog(void);
		
		Dog&	operator=(const Dog& rhs);

		virtual void	makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const Dog& x);

#endif
