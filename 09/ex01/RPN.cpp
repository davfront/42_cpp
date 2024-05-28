/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:58:41 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/22 14:34:06 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	const	RPN::_intMin(std::numeric_limits<int>::min());
int	const	RPN::_intMax(std::numeric_limits<int>::max());

bool RPN::_isOperand(std::string const & token) const
{
	if (token == "-")
		return (false);
	for (size_t i = 0; i < token.length(); i++) {
		if (!isdigit(token[i]) && (i != 0 || token[i] != '-')) {
			return (false);
		}
	}
	return (true);
}

bool RPN::_isOperator(std::string const & token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int	RPN::_calculate(int const & lhs, int const & rhs, std::string const & op) const
{
	double	result;

	if (op == "+")
		result = static_cast<double>(lhs) + rhs;
	else if (op == "-")
		result = static_cast<double>(lhs) - rhs;
	else if (op == "*")
		result = static_cast<double>(lhs) * rhs;
	else if (op == "/")
	{
		if (rhs == 0)
			throw RPN::DivisionByZeroException();
		result = static_cast<double>(lhs) / rhs;
	}
	else
		throw RPN::InvalidOperatorException();

	if (result < RPN::_intMin || result > RPN::_intMax)
		throw OperationOverflowException();
	return (result);
}

RPN::RPN(void): _expression("")
{
	return ;
}

RPN::RPN(std::string expression): _expression(expression)
{
	return ;
}

RPN::RPN(RPN const & src): _expression(src.getExpression())
{
	return ;
}

RPN::~RPN(void)
{
	return ;
}

RPN &	RPN::operator=(RPN const & rhs)
{
	this->_expression = rhs.getExpression();
	return (*this);
}

std::string const &	RPN::getExpression(void) const
{
	return (this->_expression);
}

int	RPN::solve(void)
{
	std::stack<int> operands;
	std::istringstream iss(this->_expression);
	std::string token;

	while (iss >> token)
	{
		if (RPN::_isOperand(token))
		{
			double operand = atof(token.c_str());
			if (operand < RPN::_intMin || operand > RPN::_intMax)
				throw ParsingOverflowException();
			operands.push(operand);
		}
		else if (RPN::_isOperator(token))
		{
			if (operands.size() < 2)
				throw RPN::MissingOperandException();
			int rhs = operands.top();
			operands.pop();
			int lhs = operands.top();
			operands.pop();
			operands.push(RPN::_calculate(lhs, rhs, token));
		}
		else
			throw RPN::InvalidTokenException();
	}
	if (operands.size() < 1)
		throw RPN::EmptyException();
	if (operands.size() > 1)
		throw RPN::MissingOperatorException();
	return (operands.top());
}
