/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:07 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:16:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "text_formatting.hpp"

class Bureaucrat;

class Form {

	private:

		static int const	_lowestGrade;
		static int const	_highestGrade;

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:

		Form(void);
		Form(std::string const & name, int const & gradeToSign, int const & gradeToExecute);
		Form(Form const & src);
		~Form(void);

		Form &	operator=(Form const & rhs);

		std::string const &	getName(void) const;
		bool const &		getIsSigned(void) const;
		int const &			getGradeToSign(void) const;
		int const &			getGradeToExecute(void) const;

		void	testGrades(void) const;
		void	beSigned(Bureaucrat const & signer);

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

std::ostream &	operator<<(std::ostream & o, Form const & rhs);

#endif
