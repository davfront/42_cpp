/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:04:13 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/23 17:15:32 by dapereir         ###   ########.fr       */
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
		bool	setFilter(std::string filter);

	private:
	
		typedef struct s_level {
			std::string		id;
			void			(Harl::*fn)(void) const;
			int				severity;
		}				t_level;

		static t_level const	_levels[4];

		int		_severity_filter;

		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;
};

#endif
