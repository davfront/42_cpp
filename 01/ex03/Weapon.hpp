/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:41:24 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 21:34:55 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {

	public:

		Weapon(std::string type);
		~Weapon(void);

		std::string const &	getType(void) const;
		void				setType(std::string type);

	private:
	
		std::string	_type;

};

#endif
