/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:55:15 by snaggara          #+#    #+#             */
/*   Updated: 2023/11/04 19:32:07 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern()
{
	_arrayFormIKnow[0] = "shrubbery creation";
	_arrayFormIKnow[1] = "robotomy request";
	_arrayFormIKnow[2] = "presidential pardon";

}

AForm	*Intern::makeForm(std::string const& formName, std::string const& target)
{
	if (!_verifyFormExist(formName))
		throw Intern::FormDontExist(formName);
	return _createForm(formName, target);
}

bool	Intern::_verifyFormExist(std::string const& formName) const
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == _arrayFormIKnow[i])
			return (true);
	}
	return (false);
}

AForm	*Intern::_createForm(std::string const& formName, std::string const& target)
{
	AForm *to_return = NULL;

	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);

	for (int i = 0; i < 3; i++)
	{
		if (formName == _arrayFormIKnow[i])
			to_return = forms[i];
		else
		{
			delete forms[i];
			forms[i] = NULL;
		}
	}
	return (to_return);
}
