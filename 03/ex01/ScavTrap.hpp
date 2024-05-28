/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:37 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/25 00:47:26 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{

	public:

		ScavTrap(void);
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		
		ScavTrap&	operator=(ScavTrap const & rhs);

		void	guardGate(void);

};

std::ostream &	operator<<(std::ostream & o, ScavTrap const & x);

#endif
