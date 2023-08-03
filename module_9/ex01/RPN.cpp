/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:53:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/01 12:05:34 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN(queueChar_t const& rpnInput)
	: _rpnInput(rpnInput)
	{}

RPN::RPN(RPN const& otherRpn)
	: _rpnInput(otherRpn._rpnInput)
{}

RPN::~RPN(){}

RPN&	RPN::operator=(RPN const& otherRpn)
{
	_rpnInput = otherRpn._rpnInput;
	return (*this);
}


int&		RPN::calculate()
{
	while (!_rpnInput.empty())
	{
		type_t	type = _getType(_rpnInput.front());
		if (type == NUMBER)
			_addToStack(_rpnInput.front());
		else
			_doOperation(_rpnInput.front());
		_rpnInput.pop();
	}
	if (_stack.size() != 1)
		throw InvalideRpnOperation();
	return (_stack.top());
}

void	RPN::_doOperation(char const& c)
{
	int	nb1 = _stack.top();
	_stack.pop();
	if (_stack.empty())
		throw	StackEmpty();
	int	nb2 = _stack.top();
	_stack.pop();
	if (c == '+')
		_stack.push(nb2 + nb1);
	else if (c == '-')
		_stack.push(nb2 - nb1);
	else if (c == '*')
		_stack.push(nb2 * nb1);
	else if (c == '/')
		_stack.push(nb2 / nb1);
	else
		throw InvalidOperation();
}

void	RPN::_addToStack(char & c)
{
	int nb = c - '0';
	_stack.push(nb);
}

type_t		RPN::_getType(char const& c) const
{
	if (c >= '0' && c <= '9')
		return (NUMBER);
	else if (c == '+')
		return (ADDITION);
	else if (c == '-')
		return (SOUSTRACTION);
	else if (c == '*')
		return (MULTIPLICATION);
	else if (c == '/')
		return (DIVISION);
	else
		throw CharNotValid();
}
