/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:01:31 by snaggara          #+#    #+#             */
/*   Updated: 2023/11/04 19:20:07 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__
# define __BUREAUCRAT__

#include <exception>
#include <string>
#include <iostream>

class Form;

const std::string RED = "\033[1;31m";
const std::string RESET = "\033[0m";

class Bureaucrat
{
private:
	std::string const _name;
	int			_grade;
	Bureaucrat&	operator=(Bureaucrat const& bureaucrat);
public:
	Bureaucrat(void);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const& bureaucrat);
	virtual 	~Bureaucrat();
	std::string	getName() const;
	int			getGrade() const;
	int			gradeIncrement(int const nb_inc);
	int			gradeDecrement(int const nb_dec);

	void		signForm(Form & form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(Bureaucrat const& bureaucrat) throw(): _errorPhrase(RED + "Grade too high for " + bureaucrat._name + RESET){};
		virtual ~GradeTooHighException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(Bureaucrat const& bureaucrat) throw(): _errorPhrase(RED + "Grade too low for " + bureaucrat._name + RESET){};
		virtual ~GradeTooLowException() throw(){};
		virtual const char* what() const throw()
		{
			return _errorPhrase.c_str();
		}
	private:
		std::string _errorPhrase;
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);


/*
Sam, le fait d'avoir creé un constructeur pour la class d'erreur
a l'air d'avoir créé un destructeur aussi, genre automatiquement
Du coup, il a été créé sans le throw(), et il override celui de la class exeption
Du coup sans le throw(), y'a pleins d'erreurs chelou qui sont levé, et ça marche pas
Donc on semble obligé de creer un destructeur dans le vide.
*/
#endif