/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:38:19 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:18:56 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void)src;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void)rhs;
	return (*this);
}

bool	ScalarConverter::isChar(std::string const & s)
{
	return (s.length() == 1 && !isdigit(s[0]));
}

bool	ScalarConverter::isInt(std::string const & s)
{
	bool	is_negative = (s[0] == '-');
	if (s.length() <= is_negative)
		return (false);
	for (size_t i = is_negative; i < s.length(); i++) {
		if (!isdigit(s[i]))
			return false;
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string const & s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);
	if (s.empty() || s[s.length() - 1] != 'f')
		return (false);
	size_t dotPos = s.find('.');
	if (dotPos == std::string::npos)
		return (false);
	std::string integerPartStr = s.substr(0, dotPos);
	if (!ScalarConverter::isInt(integerPartStr))
		return (false);
	std::string decimalPartStr = s.substr(dotPos + 1, s.length() - dotPos - 2);
	if (!ScalarConverter::isInt(decimalPartStr) || decimalPartStr[0] == '-')
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(std::string const & s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);
	if (s.empty())
		return (false);
	size_t dotPos = s.find('.');
	if (dotPos == std::string::npos)
		return (false);
	std::string integerPartStr = s.substr(0, dotPos);
	if (!ScalarConverter::isInt(integerPartStr))
		return (false);
	std::string decimalPartStr = s.substr(dotPos + 1, s.length() - dotPos - 1);
	if (!ScalarConverter::isInt(decimalPartStr) || decimalPartStr[0] == '-')
		return (false);
	return (true);
}

ScalarConverter::Type	ScalarConverter::getType(std::string const & s)
{
	if (ScalarConverter::isChar(s))
		return (CHAR);
	if (ScalarConverter::isInt(s))
		return (INT);
	if (ScalarConverter::isFloat(s))
		return (FLOAT);
	if (ScalarConverter::isDouble(s))
		return (DOUBLE);
	return (UNDEFINED);
}

bool	ScalarConverter::overflowsChar(double const & v)
{
	return (!std::isfinite(v) || v < std::numeric_limits<char>::min() || v > std::numeric_limits<char>::max());
}

bool	ScalarConverter::overflowsInt(double const & v)
{
	return (!std::isfinite(v) || v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max());
}

void ScalarConverter::printChar(double v, ScalarConverter::Type originalType)
{
	(void)originalType;

	if (ScalarConverter::overflowsChar(v))
	{
		std::cout << "char: impossible" << std::endl;
		return;	
	}

	char c = static_cast<char>(v);
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
}

void ScalarConverter::printInt(double v, ScalarConverter::Type originalType)
{
	(void)originalType;

	if (!ScalarConverter::overflowsInt(v))
		std::cout << "int: " << static_cast<int>(v) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat(double v, ScalarConverter::Type originalType)
{
	(void)originalType;

	float f = static_cast<float>(v);
	if (std::isfinite(f))
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"  << std::endl;
	else if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f) && f > 0)
		std::cout << "float: +inff" << std::endl;
	else if (std::isinf(f) && f < 0)
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
}

void ScalarConverter::printDouble(double v, ScalarConverter::Type originalType)
{
	(void)originalType;

	if (std::isfinite(v))
		std::cout << "double: " << std::fixed << std::setprecision(1) << v  << std::endl;
	else if (std::isnan(v))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(v) && v > 0)
		std::cout << "double: +inf" << std::endl;
	else if (std::isinf(v) && v < 0)
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	ScalarConverter::convert(std::string const & s)
{
	try {

		ScalarConverter::Type type = ScalarConverter::getType(s);
		if (type == UNDEFINED)
			throw ScalarConverter::ImpossibleConversionException();

		double v = 0;
		if (s == "nanf" || s == "nan")
			v = std::numeric_limits<double>::quiet_NaN();
		else if (s == "+inf" || s == "+inf")
			v = std::numeric_limits<double>::infinity();
		else if (s == "-inf" || s == "-inff")
			v = -std::numeric_limits<double>::infinity();
		else if (type == CHAR)
			v = s[0];
		else
			v = atof(s.c_str());

		if (type == INT && ScalarConverter::overflowsInt(v))
			throw ScalarConverter::ImpossibleConversionException();

		if (type == FLOAT && std::isfinite(v))
			v = static_cast<float>(v);

		ScalarConverter::printChar(v, type);
		ScalarConverter::printInt(v, type);
		ScalarConverter::printFloat(v, type);
		ScalarConverter::printDouble(v, type);

	} catch(std::exception &) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
