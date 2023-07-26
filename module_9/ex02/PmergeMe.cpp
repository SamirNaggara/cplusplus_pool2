/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:47 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/26 15:37:58 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <utility>
#include <algorithm>

PmergeMe::PmergeMe(){};

PmergeMe&	PmergeMe::operator=(PmergeMe const& other)
{
	(void)other;
	return (*this);
}
PmergeMe::PmergeMe(PmergeMe const& other)
	{(void)other;}

// End private coplieen methods



intVector_t	PmergeMe::mergeSort(intVector_t& originalVector)
{
	intVector_t returnVector(1,0);
	if (originalVector.size() == 1)
		return _sortOneElement(originalVector);

	pairVector_t orderedVector = _createPairs(originalVector);

	std::for_each(orderedVector.begin(), orderedVector.end(), _orderPairDecreasing);

	intVector_t firstPairVector(orderedVector.size());
	std::transform(orderedVector.begin(), orderedVector.end(), firstPairVector.begin(), _get_second);


	firstPairVector = mergeSort(firstPairVector);
	for (intVectorIt_t it = firstPairVector.begin(); it != firstPairVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return (returnVector);

}


int	PmergeMe::_get_second(std::pair<int, int> pair)
{
	return (pair.first);
}

int	PmergeMe::_found_second(int const &nb, pairVector_t &pairs)
	{
		for (pairVectorIt_t it = pairs.begin(); it != pairs.end(); it++)
		{
			if (it->first == nb)
				return (it->second);
		}
		throw FirstNotFound();

		// Pour visualiser un premier, et son second
		//std::cout << "If the first element is" << orderedVector.at(1).first << " the second one is" << _get_second(orderedVector.at(1).first, orderedVector) << std::endl;

	}

void PmergeMe::_orderPairDecreasing(std::pair<int,int> &pair)
{
	if (pair.first < pair.second)
		std::swap(pair.first, pair.second);


}


pairVector_t PmergeMe::_createPairs(intVector_t & originalVector)
{
	pairVector_t orderedVector;
	
	for (intVectorIt_t it = originalVector.begin(); it != originalVector.end(); it+=2)
	{
		if (it + 1 == originalVector.end())
			break ;
		orderedVector.push_back(std::make_pair(*it, *(it + 1)));
	}
	// Pour visualiser la pair
	// for (pairVectorIt_t it = orderedVector.begin(); it != orderedVector.end(); it++)
	// {
	// 	std::cout << "Voila le premier element : " << (*it).first;
	// 	std::cout << "\nVoila le deuxieme element : " << (*it).second;
	// 	std::cout << std::endl;
	// }
	return (orderedVector);
}


intVector_t PmergeMe::_sortOneElement(intVector_t& originalVector)
{
	intVector_t returnVector(1, originalVector.at(0));
	return (returnVector);
}



