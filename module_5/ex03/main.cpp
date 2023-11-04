/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:19:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/11/04 19:37:57 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << std::endl << std::endl << "Test de creer un Robotomy" << std::endl << std::endl;

	try{
		Bureaucrat simon("Simon", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		simon.sign(*rrf);
		simon.execute(*rrf);

		rrf->print(std::cout);
		delete rrf;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test de creer un Schrubbery" << std::endl << std::endl;

	try{
		Bureaucrat simon("Simon", 1);
		Intern someRandomIntern;
		AForm* sb;
		sb = someRandomIntern.makeForm("shrubbery creation", "test");

		simon.sign(*sb);
		simon.execute(*sb);

		sb->print(std::cout);
		std::cout << *sb;

		delete sb;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	std::cout << std::endl << std::endl << "Test de creer un presidential pardon" << std::endl << std::endl;

	try{
		Bureaucrat simon("Simon", 1);
		Intern someRandomIntern;
		AForm* pardon;
		pardon = someRandomIntern.makeForm("presidential pardon", "test");

		simon.sign(*pardon);
		simon.execute(*pardon);

		pardon->print(std::cout);

		delete pardon;

	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test de creer n'importe quoi" << std::endl << std::endl;

	try{
		Intern someRandomIntern;
		AForm* fail;

		fail = someRandomIntern.makeForm("blablabla", "test");
		delete fail;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	return (0);
}