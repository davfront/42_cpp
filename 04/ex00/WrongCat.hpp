/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:02:01 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/30 14:06:29 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include "text_formatting.hpp"

class WrongCat: public WrongAnimal
{

	public:

		WrongCat(void);
		WrongCat(const WrongCat& src);
		~WrongCat(void);
		
		WrongCat&	operator=(const WrongCat& rhs);

		void	makeSound(void) const;

};

std::ostream&	operator<<(std::ostream& o, const WrongCat& x);

#endif
