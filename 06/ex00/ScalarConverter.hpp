/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:10:36 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:16:10 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <sstream>
# include <limits>

class ScalarConverter {

	private:
	
		enum Type {
			UNDEFINED,
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		};

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);
		ScalarConverter &	operator=(ScalarConverter const & rhs);
		
		static bool	isChar(std::string const & s);
		static bool	isInt(std::string const & s);
		static bool	isFloat(std::string const & s);
		static bool	isDouble(std::string const & s);

		static Type	getType(std::string const & s);

		static bool	overflowsChar(double const & v);
		static bool	overflowsInt(double const & v);

		static void printChar(double v, Type originalType);
		static void printInt(double v, Type originalType);
		static void printFloat(double v, Type originalType);
		static void printDouble(double v, Type originalType);

	public:

		static void	convert(std::string const & s);
	
		class ImpossibleConversionException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("impossible conversion");
				}
		};

};

#endif
