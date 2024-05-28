/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:41:24 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/15 12:44:49 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanA {

	public:

		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		void	attack(void);

	private:

		std::string	_name;
		Weapon&		_weapon;

};

#endif
