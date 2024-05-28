/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:03:26 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:16:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "text_formatting.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm {

	private:

		std::string	_target;

	public:
	
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);

		std::string const &	getTarget(void) const;

		virtual void			execute(Bureaucrat const & executor) const;
		virtual std::ostream &	print(std::ostream & o) const;

};

#endif
