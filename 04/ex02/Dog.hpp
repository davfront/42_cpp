/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:01 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 20:22:08 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include "text_formatting.hpp"

class Dog: public AAnimal
{

	private:

		Brain*	_brain;

	public:

		Dog(void);
		Dog(const Dog& src);
		virtual ~Dog(void);
		
		Dog&	operator=(const Dog& rhs);

		virtual const Brain*	getBrain(void) const;
		virtual void			setBrain(Brain* brain_p);
		virtual void			deleteBrain(void);

		virtual std::string		getIdea(const int& index) const;
		virtual void			setIdea(const int& index, const std::string& idea);

		virtual void			makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const Dog& x);

#endif
