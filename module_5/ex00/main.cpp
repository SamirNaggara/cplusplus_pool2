/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:19:46 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/17 01:41:56 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

int	main()
{
	/* Test de creer martin dans la stack et d'afficher*/
	try{
		Bureaucrat martin("martin", 150);
		std::cout << martin.getName() << " est un bureaucrate de niveau " << martin.getGrade() << std::endl;
		std::cout << martin;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	/* Test de creer george dans la heap et d'afficher*/
	try{
		Bureaucrat *george = new Bureaucrat("george", 200);
		std::cout << *george;
		delete george;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	/* Test de creer une copie d'un autre membre, et de l'afficher*/
	try{
		Bureaucrat sam("Sam", 11);
		Bureaucrat bill(sam);

		std::cout << sam;
		std::cout << bill;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	/* Test d'incrementer un peu trop*/
	try{
		Bureaucrat beyonce("beyonce", 10);
		beyonce.gradeIncrement(20);
		std::cout << beyonce;
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	/* Test de decrement un peu trop*/
	try{
		Bureaucrat will("will", 140);
		will.gradeDecrement(20);
		std::cerr << will;
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}