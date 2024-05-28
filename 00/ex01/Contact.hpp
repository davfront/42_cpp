/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:24:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/14 09:06:09 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include "cli_utils.hpp"

class	Contact
{

public:

	Contact(void);
	~Contact(void);

	std::string	getFirstname(void) const;
	std::string	getLastname(void) const;
	std::string	getNickname(void) const;
	bool		is_valid(void) const;
	bool		cli_init(void);
	void		cli_print(void) const;

private:

	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;

};

#endif