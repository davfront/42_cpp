/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:37 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 23:52:19 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include "text_formatting.hpp"

class ClapTrap {
	
	private:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:

		ClapTrap(void);
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		
		ClapTrap&	operator=(ClapTrap const & rhs);

		std::string		getName(void) const;
		void			setName(std::string const & name);
		unsigned int	getHitPoints(void) const;
		void			setHitPoints(unsigned int const & hitPoints);
		unsigned int	getEnergyPoints(void) const;
		void			setEnergyPoints(unsigned int const & energyPoints);
		unsigned int	getAttackDamage(void) const;
		void			setAttackDamage(unsigned int const & attackDamage);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

std::ostream &	operator<<(std::ostream & o, ClapTrap const & x);

#endif
