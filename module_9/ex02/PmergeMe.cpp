/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:47 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/26 19:46:02 by snaggara         ###   ########.fr       */
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



intDeque_t	PmergeMe::mergeSort(intDeque_t& originalDeque)
{
	intDeque_t returndeque(1,0);
	if (originalDeque.size() == 1)
		return _sortOneElement(originalDeque);

	// On cree un vecteur contenant les pairs
	_pairDeque = _createPairs(originalDeque);

	// On s'assure que le first est le plus grand !
	std::for_each(_pairDeque.begin(), _pairDeque.end(), _orderPairDecreasing);

	// On cree un firstpairDeque, contenant uniquement les plands grands nombres de chaque pair
	intDeque_t 	_firstPairDeque;

	std::transform(_pairDeque.begin(), _pairDeque.end(), std::back_inserter(_firstPairDeque), _get_second);


	for (intdequeIt_t it = _firstPairDeque.begin(); it != _firstPairDeque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	/* Ordonne par recursion les pairs de vecteurs*/
	PmergeMe merge;
	_firstPairDeque = merge.mergeSort(_firstPairDeque);

	/* Ajoute les autres elements*/

	//_addSecondElements();
	return (_firstPairDeque);

}

/*Créée une fonction dichtomie
Elle prends un iterateur de debut et de fin en parametre
Et on connais la longueur dans laquelle on regarde
Elle regarde au milieu de ce tableau si elle peut inserer la, sinon c'est a gauche ou a droite
Puis, elle regarde a nouveau au milieu si elle peut inserer la
etc etc...
Jusqu'a trouver ou inserer le nombre, et la, elle insere*/

// void	PmergeMe::addSecondElements()
// {
// 	_firstPairDeque.push_front(_found_second(_firstPairDeque.at(0)));

// 	int i = 0;
// 	for (intdequeIt_t it = _firstPairDeque.begin() + 1; it != _firstPairDeque.end(); it++)
// 	{
// 		add_by_dichotomie(
// 			_found_second(_firstPairDeque.at(0)),  // Le nb a ajouté par dicho
// 			firstPairDeque.begin(), 				// Le debut
// 			firstPairDeque.begin() + 2 * i + 1),
// 			1;			// La fin de ou il doit essayé d'inserer
// 	}
// }


int	PmergeMe::_get_second(std::pair<int, int> pair)
{
	return (pair.first);
}

int	PmergeMe::_found_second(int const &nb, pairDeque_t &pairs)
	{
		for (pairDequeIt_t it = pairs.begin(); it != pairs.end(); it++)
		{
			if (it->first == nb)
				return (it->second);
		}
		throw FirstNotFound();

		// Pour visualiser un premier, et son second
		//std::cout << "If the first element is" << ordereddeque.at(1).first << " the second one is" << _get_second(ordereddeque.at(1).first, ordereddeque) << std::endl;

	}

void PmergeMe::_orderPairDecreasing(std::pair<int,int> &pair)
{
	if (pair.first < pair.second)
		std::swap(pair.first, pair.second);


}


pairDeque_t PmergeMe::_createPairs(intDeque_t & originalDeque)
{
	pairDeque_t ordereddeque;
	
	for (intdequeIt_t it = originalDeque.begin(); it != originalDeque.end(); it+=2)
	{
		if (it + 1 == originalDeque.end())
			break ;
		ordereddeque.push_back(std::make_pair(*it, *(it + 1)));
	}
	// Pour visualiser la pair
	// for (pairDequeIt_t it = ordereddeque.begin(); it != ordereddeque.end(); it++)
	// {
	// 	std::cout << "Voila le premier element : " << (*it).first;
	// 	std::cout << "\nVoila le deuxieme element : " << (*it).second;
	// 	std::cout << std::endl;
	// }
	return (ordereddeque);
}


intDeque_t PmergeMe::_sortOneElement(intDeque_t& originalDeque)
{
	intDeque_t returndeque(1, originalDeque.at(0));
	return (returndeque);
}



