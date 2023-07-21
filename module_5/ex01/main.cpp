/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:19:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/17 12:37:57 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << std::endl << std::endl << "Quand tout vas bien" << std::endl << std::endl;
	try {
		Bureaucrat	anna("Anna", 25);
		Form		form1("Form 1", 50, 100);
		std::cout << std::endl;
		std::cout << form1;
		std::cout << std::endl;
		anna.signForm(form1);
		std::cout << std::endl;
		std::cout << anna;
		std::cout << std::endl;
		std::cout << form1;
		std::cout << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Quand le formulaire est mal créé" << std::endl << std::endl;
	try {
		Bureaucrat	anna("Anna", 25);
		Form		form1("Form 1", 50, 100);
		//Form		form2("Form 2", 200, 100);
		//Form		form3("Form 3", 50, 500);
		Form		form4("Form 4", 50, -10);
		anna.signForm(form1);
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "Quand la signature n'est pas possible" << std::endl << std::endl;
	try {
		Bureaucrat	anna("Anna", 120);
		Form		form5("Form 5", 50, 100);

		anna.signForm(form5);
		//form5.beSigned(anna);

	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}





	return (0);
}