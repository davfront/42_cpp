/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 20:32:16 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "Brain.hpp"

class AAnimal {
	
	protected:

		std::string		_type;

	public:

		AAnimal(void);
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& src);
		virtual ~AAnimal(void);
		
		AAnimal&	operator=(const AAnimal& rhs);

		const std::string&	getType(void) const;

		virtual const Brain*	getBrain(void) const = 0;
		virtual void			setBrain(Brain* brain_p) = 0;
		virtual void			deleteBrain(void) = 0;

		virtual std::string		getIdea(const int& index) const = 0;
		virtual void			setIdea(const int& index, const std::string& idea) = 0;

		virtual void			makeSound(void) const = 0;

};

std::ostream&	operator<<(std::ostream& o, const AAnimal& x);

#endif
