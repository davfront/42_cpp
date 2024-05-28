/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:03:37 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:16:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <string>
# include <iostream>
# include <fstream>
# include "text_formatting.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm {

	private:

		std::string	_target;

	public:
	
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);

		std::string const &	getTarget(void) const;

		virtual void			execute(Bureaucrat const & executor) const;
		virtual std::ostream &	print(std::ostream & o) const;

};

#endif
