/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 11:56:05 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "AMateria.hpp"

class Cure: public AMateria
{

	public:

		Cure(void);
		Cure(Cure const & src);
		virtual ~Cure(void);

		Cure&	operator=(Cure const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);

};

#endif
