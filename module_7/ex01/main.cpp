/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:00:28 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/23 00:37:13 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main()
{
	// Test avec char
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	std::cout << "Alphabet : " << alphabet << std::endl;

	::iter<char, void>(alphabet, 27, add_one<char>);

	std::cout << "Alphabet +1 : " << alphabet << std::endl << std::endl;

	// Test avec int
	int	numbers[] = {0,1,2,3,4,5,6,7,8,9};

	std::cout << "Numbers : ";
	for (size_t i = 0 ; i < 10; i++)
		std::cout << numbers[i];
	std::cout  << std::endl;
	::iter<int, void>(numbers, 10, add_one<int>);

	std::cout << "Numbers +1 : ";
	for (size_t i = 0 ; i < 10; i++)
		std::cout << numbers[i];
	std::cout  << std::endl;
	std::cout  << std::endl;

	// Test avec bool
	bool tab[] = {true, false, false, true, true};
	std::cout << "Bools : ";
	for (size_t i = 0 ; i < 5; i++)
		std::cout << tab[i];
	std::cout  << std::endl;
	::iter<bool, void>(tab, 5, inverseBool);
	std::cout << "Bools inverse: ";
	for (size_t i = 0 ; i < 5; i++)
		std::cout << tab[i];
	std::cout  << std::endl;
	std::cout  << std::endl;

	// Test avec float
	double floatNumbers[] = {25, 543.4, -35.0, 42.5};
	std::cout << "Double : ";
	for (size_t i = 0 ; i < 4; i++)
		std::cout << floatNumbers[i] << ", ";
	std::cout  << std::endl;
	::iter<double, bool>(floatNumbers, 4, round_sam);
	std::cout << "Double round: ";
	for (size_t i = 0 ; i < 4; i++)
		std::cout << floatNumbers[i] << ", ";
	std::cout  << std::endl;

}