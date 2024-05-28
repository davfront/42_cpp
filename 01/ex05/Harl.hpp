/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:04:13 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/16 04:32:53 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define	HARL_HPP

# include <iostream>

class Harl {

	public:

		Harl(void);
		~Harl(void);

		void	complain(std::string level) const;

	private:
	
		typedef struct s_level {
			std::string		id;
			void			(Harl::*fn)(void) const;
		}				t_level;

		static t_level const	_levels[4];

		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;
};

#endif
