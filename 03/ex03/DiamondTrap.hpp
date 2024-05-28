/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:37 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 03:12:01 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

	private:

		std::string	_name;

	public:

		DiamondTrap(void);
		DiamondTrap(std::string const & name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);
		
		DiamondTrap&	operator=(DiamondTrap const & rhs);

		using ScavTrap::attack;

		std::string const &	getDiamondName(void) const;
		
		void	whoAmI(void);

};

std::ostream &	operator<<(std::ostream & o, DiamondTrap const & x);

#endif
