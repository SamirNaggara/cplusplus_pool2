/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:28:52 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 17:09:37 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <exception>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& scform) : AForm("ShrubberyCreationForm", 145, 137),
		_target(scform._target)
{
	//std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& scform)
{
	//std::cout << "ShrubberyCreationForm affectation operator called" << std::endl;
	_target = scform._target;
	return (*this);
}

std::string	ShrubberyCreationForm::get_target() const
{
	return (_target);
}


std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& scform)
{
	scform.print(os);
	std::cout << "	Target name : " << scform.get_target() << std::endl;
	return (os);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& bureaucrat) const
{
	if (!getIsSigned())
		throw AForm::NotAbleToExeException(bureaucrat, *this, "The form is not signed");
	if (bureaucrat.getGrade() > getGradeToExe())
		throw AForm::NotAbleToExeException(bureaucrat, *this, "Grade of bureaucrate insuffisant");
	
	std::string fileName = _target + "_shrubbery";
	std::ofstream monFlux(fileName.c_str());

	if (!monFlux)
		throw std::runtime_error("Le fichier ne s'est pas créé correctement");
	monFlux << ASCII_TREE << ASCII_TREE << ASCII_TREE << std::endl;
	return ;
}

std::ostream&			ShrubberyCreationForm::print(std::ostream& os) const
{
	AForm::print(os);
	os << "	Target : " << _target << std::endl;
	return (os);
}