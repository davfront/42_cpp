/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/02 11:56:17 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "AMateria.hpp"

class Ice: public AMateria
{

	public:

		Ice(void);
		Ice(Ice const & src);
		virtual ~Ice(void);

		Ice&	operator=(Ice const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);

};

#endif
