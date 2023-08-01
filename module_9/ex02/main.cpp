/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:21:48 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/01 11:45:34 by snaggara         ###   ########.fr       */
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
	double diff = diffSeconds * 1000000 + diffMicroseconds;
	return (diff * 1);

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


		PmergeMe<intDeque_t> merge(originalDeque);
		intDeque_t result = merge.mergeSort();

		double diff = ::getDiffTime(start);
		std::cout << "Before :  ";
		displayContainer<intDeque_t>(originalDeque);
		std::cout << "After :  ";
		displayContainer<intDeque_t>(result);
		std::cout << "\nTime to proceed a range of " << result.size() << " elements with std::deque :"
					<< diff << "µs";
	}
	catch (PmergeMe<intDeque_t>::DuplicateNumbers const& e)
	{
		std::cout << "\n\n\n\033[031m" << e.what() << "\n\033[0mNumber : " << e.nb << std::endl;
	}
	catch (const std::exception& ex) {
    }

	try{
		struct timeval	start;
    	gettimeofday(&start, NULL);

		intVector_t originalVector = ::createContainer<intVector_t >(ac, av);

		PmergeMe<intVector_t> merge(originalVector);
		(void)merge;
		intVector_t result = merge.mergeSort();

		double diff = ::getDiffTime(start);
		std::cout << "\nTime to proceed a range of " << result.size() << " elements with std::vector :"
					<< diff << " µs";

	}
	catch (PmergeMe<intDeque_t>::DuplicateNumbers const& e)
	{
		std::cout << "\n\n\n" << e.what() << "\nNumber : " << e.nb << std::endl;
	}
	catch (const std::exception& ex) {
    }
}
