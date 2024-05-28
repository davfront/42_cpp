/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:01 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 20:22:08 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include "text_formatting.hpp"

class Cat: public AAnimal
{

	private:

		Brain*	_brain;

	public:

		Cat(void);
		Cat(const Cat& src);
		virtual ~Cat(void);
		
		Cat&	operator=(const Cat& rhs);

		virtual const Brain*	getBrain(void) const;
		virtual void			setBrain(Brain* brain_p);
		virtual void			deleteBrain(void);

		virtual std::string		getIdea(const int& index) const;
		virtual void			setIdea(const int& index, const std::string& idea);

		virtual void			makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const Cat& x);

#endif
