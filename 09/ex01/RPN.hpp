/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:38:04 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/22 14:30:27 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <stdexcept>
# include <string>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <iostream>

class RPN {

	private:

		std::string		_expression;

		bool	_isOperand(std::string const & token) const;
		bool	_isOperator(std::string const & token) const;
		int		_calculate(int const & lhs, int const & rhs, std::string const & op) const;

		static int const _intMin;
		static int const _intMax;

	public:

		RPN(void);
		RPN(std::string expression);
		RPN(RPN const & src);
		~RPN(void);

		RPN &	operator=(RPN const & rhs);

		std::string const &	getExpression(void) const;

		int	solve(void);

		class InvalidRPNException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Invalid RNP expression";
				}
		};

		class DivisionByZeroException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Division by zero";
				}
		};

		class InvalidOperatorException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Invalid operator";
				}
		};

		class MissingOperandException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Missing operand";
				}
		};

		class InvalidTokenException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Invalid token";
				}
		};

		class EmptyException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Empty expression";
				}
		};

		class MissingOperatorException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Missing operator";
				}
		};

		class OperationOverflowException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Integer overflow at operation";
				}
		};

		class ParsingOverflowException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Integer overflow at parsing";
				}
		};
};

#endif
