/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:32:15 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/01 03:12:21 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN__
#define __RPN__

#include <queue>
#include <stack>
#include <exception>

typedef std::queue<char> 	queueChar_t;
typedef	std::stack<int>		stackInt_t;

enum type_t{
	NUMBER,
	ADDITION,
	SOUSTRACTION,
	MULTIPLICATION,
	DIVISION
};

class RPN
{
private:
	/* data */
	RPN(void);
	RPN(RPN const& otherRpn);
	RPN&			operator=(RPN const& otherRpn);

	type_t			_getType(char const& c) const;
	void			_addToStack(char & c);
	void			_doOperation(char const& c);

	queueChar_t		_rpnInput;
	stackInt_t		_stack;
public:
	RPN(queueChar_t const& rpnInput);
	~RPN();

	int&		calculate();

	
	class CharNotValid : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "Error\nRPN::CharNotValid : One of the char is not valid for an Reverse Polish Notation";
			}
	};

	class StackEmpty : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "Error\nRPN::StackEmpty :Operation impossible because the stack is empty. RPN invalid";
			}
	};

	class InvalidOperation : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "Error\nRPN::InvalidOperation : Trying to do an operation who is not + - * or /";
			}
	};

	class InvalideRpnOperation : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "Error\nRPN::InvalideRpnOperation : At the end, the stack should have only one number";
			}
	};
};

#endif