/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:21:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/30 23:59:53 by snaggara         ###   ########.fr       */
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
	std::cout << "\nBefore : ";
	for (std::deque<int>::iterator it = originalDeque.begin(); it != originalDeque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try{
		PmergeMe merge(originalDeque);
		std::deque<int> result = merge.mergeSort();

		std::cout << "After :  ";
		for (std::deque<int>::iterator it = result.begin(); it != result.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;
		std::cout << "Time to proceed a range of " << result.size() << " elements with std::deque :"
					<< merge.getOperationTime() * 1000 << " ms";
	}
	catch (PmergeMe::DuplicateNumbers const& e)
	{
		std::cout << e.what() << "\nNumber : " << e.nb << std::endl;
	}
}