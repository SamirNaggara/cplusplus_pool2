/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:21:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/26 13:29:27 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"
#include <string>
#include <vector>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Veuillez entrer au moins un nombre en argument\n" << std::endl;
		return (0);
	}
	int number;
	std::vector<int> originalVector;
	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		iss >> number;
		originalVector.push_back(number);
	}

	// for (std::vector<int>::iterator it = originalVector.begin(); it != originalVector.end(); it++)
	// 	std::cout << *it << std::endl;

	std::vector<int> result = PmergeMe::mergeSort(originalVector);

	std::cout << "La liste triée : " << std::endl;
	for (std::vector<int>::iterator it = result.begin(); it != result.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}