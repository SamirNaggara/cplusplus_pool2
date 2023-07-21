/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:03:31 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 15:23:13 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <cmath>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& scform) : AForm("RobotomyRequestForm", 72, 45),
		_target(scform._target)
{
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& scform)
{
	//std::cout << "RobotomyRequestForm affectation operator called" << std::endl;
	_target = scform._target;
	return (*this);
}

std::string	RobotomyRequestForm::get_target() const
{
	return (_target);
}


std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& scform)
{
	scform.print(os);
	std::cout << "	Target name : " << scform.get_target() << std::endl;
	return (os);
}

void	RobotomyRequestForm::execute(Bureaucrat const& bureaucrat) const
{
	if (!getIsSigned())
		throw AForm::NotAbleToExeException(bureaucrat, *this, "The form is not signed");
	if (bureaucrat.getGrade() > getGradeToExe())
		throw AForm::NotAbleToExeException(bureaucrat, *this, "Grade of bureaucrate insuffisant");
	
	std::cout << "Driiiiiiiiiiiiiil" << std::endl;

	// Calcul du timestamp en miliseconde, pour initialiser srand
	struct timeval tv;
    gettimeofday(&tv, NULL);
	srand(tv.tv_usec);

	int randomNum = rand() % 2;
	if (randomNum)
		std::cout << "Coup de bol, la target à été correctement Robotomisée" << std::endl;
	else
		std::cout << "Pas de chance, la target n'a pas correctement été Robotomisée" << std::endl;
		
}