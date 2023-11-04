/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:40:24 by snaggara          #+#    #+#             */
/*   Updated: 2023/11/04 19:28:05 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN__
# define __INTERN__

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm;



class Intern
{
private:
	std::string	_arrayFormIKnow[3];
	AForm* _arrayFormPtr[3];
	AForm *forms[3];
	bool	_verifyFormExist(std::string const& formName) const;
	AForm	*_createForm(std::string const& formName, std::string const& target);
public:
	Intern(void);
	Intern(Intern const& intern);
	virtual ~Intern(void){};
	Intern&	operator==(Intern const& intern);

	AForm	*makeForm(std::string const& formName, std::string const& target);




	class FormDontExist : public std::exception
	{
		private:
			std::string	_errorPhrase;
		public:
			FormDontExist(std::string const& formName) throw()
			{
				_errorPhrase = RED
					+ "L'idiot de stagiaire a encore essayé de creer un formulaire qui n'existe pas : "
					+ formName
					+ RESET;
			};
			virtual ~FormDontExist() throw() {};

			virtual const char* what() const throw()
			{
				return _errorPhrase.c_str();
			}
	};
};

	// class GradeTooLowException : public std::exception
	// {
	// public:
	// 	GradeTooLowException(Bureaucrat const& bureaucrat) throw(): _errorPhrase(RED + "Grade too low for " + bureaucrat._name + RESET){};
	// 	virtual ~GradeTooLowException() throw(){};
	// 	virtual const char* what() const throw()
	// 	{
	// 		return _errorPhrase.c_str();
	// 	}
	// private:
	// 	std::string _errorPhrase;
	// };

#endif