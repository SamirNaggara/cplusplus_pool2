/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:21:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/31 15:19:46 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"
#include <string>
#include <deque>

template<typename T>
T	createContainer(int ac, char **av)
{
	int number;
	T originalDeque;

	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		iss >> number;
		originalDeque.push_back(number);
	}
	return (originalDeque);
}

template<typename T>
void	displayContainer(T container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

double	getDiffTime(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	long diffSeconds = end.tv_sec - start.tv_sec;
	long diffMicroseconds = end.tv_usec - start.tv_usec;
	double diff = diffSeconds + diffMicroseconds * 1e-6;
	return (diff);

}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Veuillez entrer au moins un nombre en argument\n" << std::endl;
		return (0);
	}


	try{
		struct timeval	start;
    	gettimeofday(&start, NULL);

		intDeque_t originalDeque = ::createContainer<intDeque_t >(ac, av);

		std::cout << "\nTest with deque : \nBefore : ";
		displayContainer<intDeque_t>(originalDeque);

		std::cout << "After :  ";
		PmergeMe<intDeque_t> merge(originalDeque);
		intDeque_t result = merge.mergeSort();
		displayContainer<intDeque_t>(result);

		double diff = ::getDiffTime(start);
		std::cout << "\nTime to proceed a range of " << result.size() << " elements with std::deque :"
					<< diff * 100000 << " micro s";
	}
	catch (PmergeMe<intDeque_t>::DuplicateNumbers const& e)
	{
		std::cout << e.what() << "\nNumber : " << e.nb << std::endl;
	}

	try{
		struct timeval	start;
    	gettimeofday(&start, NULL);

		intVector_t originalVector = ::createContainer<intVector_t >(ac, av);

		std::cout << "\n\n\nTest with vector : \nBefore : ";
		displayContainer<intVector_t>(originalVector);

		std::cout << "After :  ";
		PmergeMe<intVector_t> merge(originalVector);
		(void)merge;
		intVector_t result = merge.mergeSort();
		displayContainer<intVector_t>(result);

		double diff = ::getDiffTime(start);
		std::cout << "\nTime to proceed a range of " << result.size() << " elements with std::deque :"
					<< diff * 1000000 << " micro s";

	}
	catch (PmergeMe<intDeque_t>::DuplicateNumbers const& e)
	{
		std::cout << e.what() << "\nNumber : " << e.nb << std::endl;
	}
}
