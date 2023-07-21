/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:10:35 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 17:02:56 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm(std::string const name, int grade_to_sign, int grade_to_exe)
	: 	_name(name),
		_is_signed(false),
		_grade_to_sign(grade_to_sign),
		_grade_to_exe(grade_to_exe)
	{
		//std::cout << "AForm constructor called" << std::endl;
		if (grade_to_sign <= 0 || grade_to_exe < 0)
			throw	AForm::GradeTooHighException(*this);
		else if (grade_to_sign > 150 || grade_to_exe > 150)
			throw	AForm::GradeTooLowException(*this);
		return ;

	}

AForm::AForm(AForm const& AForm)
	:	_name(AForm._name),
		_is_signed(false),
		_grade_to_sign(AForm._grade_to_sign),
		_grade_to_exe(AForm._grade_to_exe)
	{
		//std::cout << "AForm copy constructor called" << std::endl;
	}

AForm::~AForm(void)
{
	//std::cout << "AForm copy constructor called" << std::endl;

}

AForm&	AForm::operator=(AForm const& AForm)
{
	_name = AForm._name;
	_is_signed = false;
	_grade_to_sign = AForm._grade_to_sign;
	_grade_to_exe = AForm._grade_to_exe;
	return (*this);
}


std::string		AForm::getName(void) const
{
	return (_name);
}

bool			AForm::getIsSigned(void) const
{
	return (_is_signed);

}

int				AForm::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int				AForm::getGradeToExe(void) const
{
	return (_grade_to_exe);
}



void			AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw AForm::NotAbleToSignException(bureaucrat, *this, "Grade of bureaucrate insuffisant");
	_is_signed = true;
}

std::ostream&			AForm::print(std::ostream& os) const
{
	std::string signedStr;

	if (getIsSigned())
		signedStr = "Yes";
	else
		signedStr = "No";
	os << std::endl;
	os << "Formulaire name : " << getName() << std::endl;
	os << "	is signed : " << signedStr << std::endl;
	os << "	Grade required to signed : " << getGradeToSign() << std::endl;
	os << "	Grade required to execute : " << getGradeToExe() << std::endl;
	return (os);
}


std::ostream& operator<<(std::ostream& os, AForm const& aForm)
{
	return (aForm.print(os));
}