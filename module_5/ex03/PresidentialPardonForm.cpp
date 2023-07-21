/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:09:34 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 17:13:36 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <cmath>
#include <sys/time.h>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& scform) : AForm("PresidentialPardonForm", 25, 5),
		_target(scform._target)
{
	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& scform)
{
	//std::cout << "PresidentialPardonForm affectation operator called" << std::endl;
	_target = scform._target;
	return (*this);
}

std::string	PresidentialPardonForm::get_target() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& bureaucrat) const
{
	if (!getIsSigned())
		throw AForm::NotAbleToExeException(bureaucrat, *this, "The form is not signed");
	if (bureaucrat.getGrade() > getGradeToExe())
		throw AForm::NotAbleToExeException(bureaucrat, *this, "Grade of bureaucrate insuffisant");
	std::cout << "La target "
		<< _target
		<< " a été pardonné par Zaphod Beeblebrox"
		<< std::endl;
	
}

std::ostream&			PresidentialPardonForm::print(std::ostream& os) const
{
	AForm::print(os);
	os << "	Target : " << _target << std::endl;
	return (os);
}