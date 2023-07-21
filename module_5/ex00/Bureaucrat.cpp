/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:07:41 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/17 10:56:20 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;

	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException(*this);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const& bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& bureaucrat)
{
	_name = bureaucrat._name;
	_grade = bureaucrat._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

int		Bureaucrat::gradeIncrement(int const nb_inc)
{
	if (_grade - nb_inc <= 0)
		throw GradeTooHighException(*this);
	_grade -= nb_inc;
	return (_grade);
}

int		Bureaucrat::gradeDecrement(int const nb_dec)
{
	if (_grade + nb_dec > 150)
		throw GradeTooHighException(*this);
	_grade += nb_dec;
	return (_grade);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}