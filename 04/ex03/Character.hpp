/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/06/01 21:33:11 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "text_formatting.hpp"
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE	4

class Character: public ICharacter
{

	private:

		std::string _name;
		AMateria*	_inventory[INVENTORY_SIZE];

	public:

		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character(void);

		Character&	operator=(Character const & rhs);

		virtual std::string const &	getName(void) const;

		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);

};

#endif
