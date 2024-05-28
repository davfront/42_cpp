/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:01:12 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:16:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>
# include "text_formatting.hpp"

class AForm;

class Intern {

	private:
	
		typedef struct s_createPair {
			std::string		id;
			AForm*			(*fn)(std::string const & target);
		}				t_createPair;

		static t_createPair const	_createList[3];
		
		static AForm*	_createShrubberyCreationForm(std::string const & target);
		static AForm*	_createRobotomyRequestForm(std::string const & target);
		static AForm*	_createPresidentialPardonForm(std::string const & target);

	public:

		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern &	operator=(Intern const & rhs);

		AForm*	makeForm(std::string const & name, std::string const & target) const;

};

#endif
