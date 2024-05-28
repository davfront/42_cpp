/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:01 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 14:31:53 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include "text_formatting.hpp"

class Cat: public Animal
{

	public:

		Cat(void);
		Cat(const Cat& src);
		virtual ~Cat(void);
		
		Cat&	operator=(const Cat& rhs);

		virtual void	makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const Cat& x);

#endif
