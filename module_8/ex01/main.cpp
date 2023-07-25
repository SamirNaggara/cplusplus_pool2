/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:20:30 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/24 15:40:24 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "Span.hpp"

int	main()
{
	std::cout << "Cas basique" << std::endl;
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Cas ou on ajoute trop de combiens" << std::endl;
	try
	{
		Span spanIns(5);
		spanIns.addNumber(8);
		spanIns.addNumber(35);
		spanIns.addNumber(2);
		spanIns.addNumber(10);
		spanIns.addNumber(85);
		spanIns.addNumber(53);
		
		std::cout << "Le plus petit :" << spanIns.shortestSpan() << std::endl;
		std::cout << "Le plus grand :" << spanIns.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;


	std::cout << "Remplissons avec 5 elements : " << std::endl;
	try
	{
		t_vector random_vector(3, 0);

		std::srand(time(NULL));
		generate(random_vector.begin(), random_vector.end(), std::rand);
		
		for (t_vector_it it = random_vector.begin(); it != random_vector.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		Span spanIns(3);

		spanIns.addNumbers(random_vector.begin(), random_vector.end());
		
		std::cout << "Le plus petit :" << spanIns.shortestSpan() << std::endl;
		std::cout << "Le plus grand :" << spanIns.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	std::cout << std::endl << std::endl;


	
	return (0);
}