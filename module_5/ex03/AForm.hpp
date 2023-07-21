/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:10:43 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 16:59:58 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AForm__
# define __AForm__

#include <string>
#include <exception>
#include <sstream>

# ifndef __BUREAUCRAT__
#  include "Bureaucrat.hpp"
# endif


class AForm
{
private:
	std::string _name;
	bool		_is_signed;
	int			_grade_to_sign;
	int			_grade_to_exe;

	AForm(void);

public:
	AForm(std::string const name, int grade_to_signed, int grade_to_exe);
	AForm(AForm const& AForm);
	virtual 	~AForm(void);
	virtual AForm&	operator=(AForm const& AForm);

	std::string		getName(void) const;
	bool			getIsSigned(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExe(void) const;
	virtual std::ostream&	print(std::ostream& os) const;
	
	virtual void	beSigned(Bureaucrat const& bureaucrat);
	virtual void	execute(Bureaucrat const& bureaucrat) const = 0;

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(AForm const& AForm) throw(){
			_errorPhrase = 
				RED 
				+ "Impossible to create form. One of requiered grade is lower than limit : " 
				+ AForm._name 
				+ RESET;
		}
			
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
		GradeTooHighException(AForm const& AForm) throw(){
			_errorPhrase = 
				RED 
				+ "Impossible to create form. One of requiered grade is higher than limit : " 
				+ AForm._name 
				+ RESET;
		};
		virtual ~GradeTooHighException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};

	class NotAbleToSignException : public std::exception
	{
	public:
		NotAbleToSignException(Bureaucrat const& bureaucrat, AForm const& form, std::string reason) throw()
		{
			 _errorPhrase = 
					RED 
					+ "Le bureaucrate " 
					+ bureaucrat.getName() 
					+ " could not sign the form : " 
					+ form.getName() 
					+ "./nReason : "
					+ reason
					+ RESET;
		}
			
		virtual ~NotAbleToSignException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};

	class NotAbleToExeException : public std::exception
	{
	public:
		NotAbleToExeException(Bureaucrat const& bureaucrat, AForm const& form, std::string const& reason) throw()
		{



			 _errorPhrase = 
					RED 
					+ "Le bureaucrate " 
					+ bureaucrat.getName() 
					+ " has not enough grade to exec the form : " 
					+ form.getName() 
					+ ".\nReason : "
					+ reason
					+ RESET;
		}
			
		virtual ~NotAbleToExeException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};
};

std::ostream& operator<<(std::ostream& os, AForm const &aForm);

#endif