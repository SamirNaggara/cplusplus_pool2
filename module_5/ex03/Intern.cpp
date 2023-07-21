/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:55:15 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 17:08:09 by snaggara         ###   ########.fr       */
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
	AForm	*to_return = _createForm(formName, target);
	return to_return;
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
	AForm* formToReturn;

	if (formName == _arrayFormIKnow[0])
		formToReturn = new ShrubberyCreationForm(target);
	else if (formName == _arrayFormIKnow[1])
		formToReturn = new RobotomyRequestForm(target);
	else
		formToReturn = new PresidentialPardonForm(target);
	return (formToReturn);
}
