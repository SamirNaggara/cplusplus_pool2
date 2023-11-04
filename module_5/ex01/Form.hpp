/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:20 by snaggara          #+#    #+#             */
/*   Updated: 2023/11/04 17:46:51 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM__
# define __FORM__

#include <string>
#include <exception>

# ifndef __BUREAUCRAT__
#  include "Bureaucrat.hpp"
# endif


class Form
{
private:
	std::string const _name;
	bool		_is_signed;
	int			_grade_to_sign;
	int			_grade_to_exe;

	Form(void);

public:
	Form(std::string const name, int grade_to_signed, int grade_to_exe);
	Form(Form const& form);
	virtual 	~Form(void);
	Form&	operator=(Form const& form);

	std::string		getName(void) const;
	bool			getIsSigned(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExe(void) const;

	void			beSigned(Bureaucrat const& bureaucrat);

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(Form const& form) throw(): _errorPhrase(RED + "One of requiered grade is too low to create the form : " + form._name + RESET){};
		GradeTooLowException(Bureaucrat const& bureaucrat, Form const& form) throw(): 
			_errorPhrase(RED + bureaucrat.getName() + " tried to signed the form " + form._name + " but is not high enough." + RESET)
			{};
			
		virtual ~GradeTooLowException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(Form const& form) throw(): _errorPhrase(RED + "One of requiered grade is too high to create the form : " + form._name + RESET){};
		virtual ~GradeTooHighException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif