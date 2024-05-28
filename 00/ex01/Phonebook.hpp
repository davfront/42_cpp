/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:30:08 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/12 18:33:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "cli_utils.hpp"
# include "Contact.hpp"

# define CONTACT_MAX	8

class	Phonebook
{

public:

	Phonebook(void);
	~Phonebook(void);

	void	cli_start(void);

private:

	int		_size;
	Contact	_contacts[CONTACT_MAX];
	int		_oldest_id;

	std::string	_trunc(std::string s, size_t size) const;
	bool		_add(Contact contact);
	void		_cli_print_contacts(void) const;
	void		_cli_print_menu(void) const;
	bool		_cli_read_cmd(std::string &input) const;
	void		_cli_add(void);
	void		_cli_search(void) const;

};

#endif
