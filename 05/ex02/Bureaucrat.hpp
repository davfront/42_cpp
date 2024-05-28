/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:01:12 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:16:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "text_formatting.hpp"

class AForm;

class Bureaucrat {

	private:

		static int const	_lowestGrade;
		static int const	_highestGrade;

		std::string const	_name;
		int					_grade;

	public:

		Bureaucrat(void);
		Bureaucrat(std::string const & name, int const & grade);
		Bureaucrat(Bureaucrat const & src);

		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & rhs);

		std::string const &	getName(void) const;
		int const &			getGrade(void) const;

		void	testGrade(void) const;
		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(AForm & form) const;
		void	executeForm(AForm & form) const;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("The grade is too high.");
				}
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("The grade is too low.");
				}
		};


};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
