/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:19:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 15:19:52 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	// Shrobbery
	std::cout << std::endl << std::endl << "Test tout vas bien" << std::endl << std::endl;

	try{
		ShrubberyCreationForm	scForm("test");
		ShrubberyCreationForm	scForm2(scForm);
		Bureaucrat				michael("michael", 100);
		Bureaucrat				george(michael);


		michael.sign(scForm);
		michael.execute(scForm);

		
		
		std::cout << scForm;

		george.sign(scForm2);
		george.execute(scForm2);

		std::cout << scForm2;

	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test on oublie de signer" << std::endl << std::endl;
	try{
		ShrubberyCreationForm	scForm("test");
		Bureaucrat				michael("michael", 100);

		scForm.execute(michael);
		
		std::cout << scForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test on a pas assez de permission pour signer" << std::endl << std::endl;
	try{
		ShrubberyCreationForm	scForm("test");
		Bureaucrat				michael("michael", 200);

		michael.sign(scForm);
		michael.execute(scForm);
		
		std::cout << scForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	std::cout << std::endl << std::endl << "Test on peut signer, mais pas executé" << std::endl << std::endl;
	try{
		ShrubberyCreationForm	scForm("test");
		Bureaucrat				michael("michael", 140);

		michael.sign(scForm);
		scForm.execute(michael);
		
		std::cout << scForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	// Robotomy

	std::cout << std::endl << std::endl << "Test tout vas bien" << std::endl << std::endl;

	try{
		RobotomyRequestForm	rtForm("test");
		Bureaucrat			michael("michael", 20);

		michael.sign(rtForm);
		michael.execute(rtForm);
		
		std::cout << rtForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test on oublie de signer" << std::endl << std::endl;
	try{
		RobotomyRequestForm	rtForm("test");
		Bureaucrat				michael("michael", 20);

		rtForm.execute(michael);
		
		std::cout << rtForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test on a pas assez de permission pour signer" << std::endl << std::endl;
	try{
		RobotomyRequestForm	rtForm("test");
		Bureaucrat				michael("michael", 90);

		michael.sign(rtForm);
		michael.execute(rtForm);
		
		std::cout << rtForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	std::cout << std::endl << std::endl << "Test on peut signer, mais pas executé" << std::endl << std::endl;
	try{
		RobotomyRequestForm	rtForm("test");
		Bureaucrat				michael("michael", 50);

		michael.sign(rtForm);
		rtForm.execute(michael);
		
		std::cout << rtForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	// Présidential pardon

	// Shrobbery
	std::cout << std::endl << std::endl << "Test tout vas bien" << std::endl << std::endl;

	try{
		PresidentialPardonForm	pForm("test");
		PresidentialPardonForm	pForm2(pForm);
		Bureaucrat				michael("michael", 1);
		Bureaucrat				george(michael);


		michael.sign(pForm);
		michael.execute(pForm);

		
		
		std::cout << pForm;

		george.sign(pForm2);
		george.execute(pForm2);

		std::cout << pForm2;

	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test on oublie de signer" << std::endl << std::endl;
	try{
		PresidentialPardonForm	pForm("test");
		Bureaucrat				michael("michael", 1);

		pForm.execute(michael);
		
		std::cout << pForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Test on a pas assez de permission pour signer" << std::endl << std::endl;
	try{
		PresidentialPardonForm	pForm("test");
		Bureaucrat				michael("michael", 40);

		michael.sign(pForm);
		michael.execute(pForm);
		
		std::cout << pForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	std::cout << std::endl << std::endl << "Test on peut signer, mais pas executé" << std::endl << std::endl;
	try{
		PresidentialPardonForm	pForm("test");
		Bureaucrat				michael("michael", 10);

		michael.sign(pForm);
		pForm.execute(michael);
		
		std::cout << pForm;
	}
	catch(std::exception const& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	return (0);
}