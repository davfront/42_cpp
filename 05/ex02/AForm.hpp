/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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

class AForm {

	private:

		static int const	_lowestGrade;
		static int const	_highestGrade;

		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:

		AForm(void);
		AForm(std::string const & name, int const & gradeToSign, int const & gradeToExecute);
		AForm(AForm const & src);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & rhs);

		std::string const &	getName(void) const;
		bool const &		getIsSigned(void) const;
		int const &			getGradeToSign(void) const;
		int const &			getGradeToExecute(void) const;

		void	testGrades(void) const;
		void	beSigned(Bureaucrat const & signer);

		virtual void			execute(Bureaucrat const & executor) const = 0;
		virtual std::ostream &	print(std::ostream & o) const = 0;

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
		
		class UnsignedFormException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("The form is not signed.");
				}
		};

	protected:

		void	testExecutionBy(Bureaucrat const & executor) const;
		
};

std::ostream &	operator<<(std::ostream & o, AForm const & rhs);

#endif
