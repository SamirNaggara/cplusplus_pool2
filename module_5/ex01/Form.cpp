/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:18:17 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/17 12:37:30 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int grade_to_sign, int grade_to_exe)
	: 	_name(name),
		_is_signed(false),
		_grade_to_sign(grade_to_sign),
		_grade_to_exe(grade_to_exe)
	{
		std::cout << "Form constructor called" << std::endl;
		if (grade_to_sign <= 0 || grade_to_exe < 0)
			throw	Form::GradeTooHighException(*this);
		else if (grade_to_sign > 150 || grade_to_exe > 150)
			throw	Form::GradeTooLowException(*this);
		return ;

	}

Form::Form(Form const& form)
	:	_name(form._name),
		_is_signed(false),
		_grade_to_sign(form._grade_to_sign),
		_grade_to_exe(form._grade_to_exe)
	{
		std::cout << "Form copy constructor called" << std::endl;
	}

Form::~Form(void)
{
	std::cout << "Form copy constructor called" << std::endl;

}

Form&	Form::operator=(Form const& form)
{
	_name = form._name;
	_is_signed = false;
	_grade_to_sign = form._grade_to_sign;
	_grade_to_exe = form._grade_to_exe;
	return (*this);
}


std::string		Form::getName(void) const
{
	return (_name);
}

bool			Form::getIsSigned(void) const
{
	return (_is_signed);

}

int				Form::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int				Form::getGradeToExe(void) const
{
	return (_grade_to_exe);
}



void			Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException(bureaucrat, *this);
	_is_signed = true;
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
	std::string signedStr;

	if (form.getIsSigned())
		signedStr = "Yes";
	else
		signedStr = "No";
	os << "Formulaire name : " << form.getName() << std::endl;
	os << "is signed : " << signedStr << std::endl;
	os << "Grade required to signed : " << form.getGradeToSign() << std::endl;
	os << "Grade required to execute : " << form.getGradeToExe() << std::endl;
	return (os);
}