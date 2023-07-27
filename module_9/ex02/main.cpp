/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:21:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/27 10:10:14 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"
#include <string>
#include <deque>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Veuillez entrer au moins un nombre en argument\n" << std::endl;
		return (0);
	}

	int number;
	std::deque<int> originalDeque;
	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		iss >> number;
		originalDeque.push_back(number);
	}

	// for (std::deque<int>::iterator it = originalDeque.begin(); it != originalDeque.end(); it++)
	// 	std::cout << *it << std::endl;

	PmergeMe merge(originalDeque);
	std::deque<int> result = merge.mergeSort();

	std::cout << "La liste triée : " << std::endl;
	for (std::deque<int>::iterator it = result.begin(); it != result.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}