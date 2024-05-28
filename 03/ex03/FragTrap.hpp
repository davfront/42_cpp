/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:37 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 01:34:05 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{

	public:

		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		
		FragTrap&	operator=(FragTrap const & rhs);

		void	highFivesGuys(void);

};

std::ostream &	operator<<(std::ostream & o, FragTrap const & x);

#endif
