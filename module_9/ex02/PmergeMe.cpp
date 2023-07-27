/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:47 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/27 14:50:54 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>

/*
	Samir, tu es en pleine implémentation du truc de jacob la.
	Ton code marche bien si tu n'optimises pas avec Jacob, donc si t'utilises la fonction add_secondElement au lieu de addSecondElementWithJacob.

	Tu as créé une super fonction qui te dis pour chaque nombre s'il faut faire -1 ou + quelque chose pour respecteur l'ordre de Jacob.

	Maintenant, dans ta fonction addSecondElementWIthJacob, tu as essayé de l'imprementer mais c'est compliqué.

	Deja parce que defois Jacob te fais sortir du deque des seconds elements, donc au moment ou on fait un + il faut essayer de ramener au dernier element.

	Mais il faut aussi controler la longueuer.
	Quand tu appelles dischotomie, sur quelle longueur tu as besoin de l'appeler exactement ?
	Je pense que c'est i, mais c'est a vérifier.

	En tout cas le probleme c'est que tu segfault a partir de 4 éléments, donc il faut voir en détail ce qu'il se passe.

	Il y a aussi un doute sur la bonne opti.
	Es ce qu'il faut faire 0, puis 3, puis 2, puis 1, puis 5 puis 4, etc etc...?
	Exactement comme Jacob ?
	Ou esce qun peu différent ?
	Je pense que c'est un peu différent, mais c'est dure a determiner !!!
*/

PmergeMe::PmergeMe(){};

PmergeMe::PmergeMe(intDeque_t& originalDeque)
	:_originalDeque(originalDeque)
{
	if (jacobsthalSuit.size() == 0)
		_createJacobsthalDeque(1, 1);
	jacobsthalSuit.pop_front();
	jacobsthalSuit.push_back(-1);
	// for (intdequeIt_t it = jacobsthalSuit.begin(); it != jacobsthalSuit.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl << std::endl;
	

	
};

PmergeMe&	PmergeMe::operator=(PmergeMe const& other)
{
	(void)other;
	return (*this);
}
PmergeMe::PmergeMe(PmergeMe const& other)
	{(void)other;}

// End private coplieen methods



intDeque_t	PmergeMe::mergeSort()
{
	if (_originalDeque.size() == 1)
		return _sortOneElement(_originalDeque);

	// On cree un vecteur contenant les pairs
	_createPairs();

	// On s'assure que le first est le plus grand !
	_sortEachPair();

	// On créé un vecteur avec les premieres pairs
	_createFirstPairDeque();

	/* Ordonne par recursion les pairs de vecteurs*/
	PmergeMe merge(_firstPairDeque);
	_firstPairDeque = merge.mergeSort();


	_createSecondPairDeque();

	
	_addSecondElementsWithJacob();
	
	return (_firstPairDeque);
}

void	PmergeMe::_createSecondPairDeque()
{
	GetSecond getSecond(_pairDeque);
	
	std::transform(_firstPairDeque.begin(), _firstPairDeque.end(), std::back_inserter(_secondPairDeque), getSecond);
}


void	PmergeMe::_createFirstPairDeque()
{
	std::transform(_pairDeque.begin(), _pairDeque.end(), std::back_inserter(_firstPairDeque), _get_first);
}


void	PmergeMe::_sortEachPair()
{
	std::for_each(_pairDeque.begin(), _pairDeque.end(), _orderPairDecreasing);
}


/*Créée une fonction dichtomie
Elle prends un iterateur de debut et de fin en parametre
Et on connais la longueur dans laquelle on regarde
Elle regarde au milieu de ce tableau si elle peut inserer la, sinon c'est a gauche ou a droite
Puis, elle regarde a nouveau au milieu si elle peut inserer la
etc etc...
Jusqu'a trouver ou inserer le nombre, et la, elle insere*/

void	PmergeMe::_addSecondElements()
{
	int i = 0;       
	intdequeIt_t it = _secondPairDeque.begin();

	// Le premier element est juste poussé, ce sera automatiquement dans l'ordre
	_firstPairDeque.push_front(*it);

	it = _secondPairDeque.erase(it);
	while (it != _secondPairDeque.end())
	{
		_add_by_dichotomie(
			*it,  // Le nb a ajouté par dicho
			_firstPairDeque.begin(), 				// Le debut
			2 * i + 1);								// La fin de ou il doit essayé d'inserer
		it = _secondPairDeque.erase(it);
		i++;
	}
	// Si la liste est impaire, faut pas oublier d'ajouter le petit dernier
	if (_originalDeque.size() % 2 == 1)
	{
		//_firstPairDeque.push_back(*(_originalDeque.end() - 1));
		_add_by_dichotomie(*(_originalDeque.end() - 1), _firstPairDeque.begin(), _firstPairDeque.size() - 1);
	}
}

void	PmergeMe::_addSecondElementsWithJacob()
{
	int i = 0;
	size_t compteur = 0;    
	intdequeIt_t it = _secondPairDeque.begin();

	// Le premier element est juste poussé, ce sera automatiquement dans l'ordre
	_firstPairDeque.push_front(*it);
	compteur++;

	int offset = _jacobOffset(i);
	if (offset == -1)
	{
		i--;
		it--;
	}
	else{
		for (int j = 0; j < offset; i++)
		{
			it++;
			i++;
			if (it == _secondPairDeque.end())
			{
				it--;
				break;
			}
		}
	}
	it+=offset;
	while (compteur < _secondPairDeque.size())
	{
		_add_by_dichotomie(
			*it,  // Le nb a ajouté par dicho
			_firstPairDeque.begin(), 				// Le debut
			2 * i + 1);								// La fin de ou il doit essayé d'inserer

		compteur++;
		
		if (offset == -1)
		{
			i--;
			it--;
		}
		else{
			for (int j = 0; j < offset; i++)
			{
				it++;
				i++;
				if (it == _secondPairDeque.end())
				{
					it--;
					break;
				}
			}
		}
	}
	// Si la liste est impaire, faut pas oublier d'ajouter le petit dernier
	if (_originalDeque.size() % 2 == 1)
	{
		//_firstPairDeque.push_back(*(_originalDeque.end() - 1));
		_add_by_dichotomie(*(_originalDeque.end() - 1), _firstPairDeque.begin(), _firstPairDeque.size() - 1);
	}
}

/*
	Fonction qui marche par recursion.
	Si la longueur est 1, on insere soit a gauche soit a droite
	Si c'est au dessus, on compare avec ce qui est au milieu, et on rappel
	reccursivement soit a gauche soit a droite 
*/
void	PmergeMe::_add_by_dichotomie(int nb, intdequeIt_t begin, int length)
{
	int	half = (length / 2);
	
	if (length == 0)
	{
		if (nb < *begin)
			_firstPairDeque.insert(begin, nb);
		else
			_firstPairDeque.insert(begin + 1, nb);
	}
	else if (length == 1)
	{
		if (nb < *(begin + half))
			_add_by_dichotomie(nb, begin, half);
		else
			_add_by_dichotomie(nb, begin + 1, half);
	}
	else if (length % 2 == 1)
	{
		if (nb < *(begin + half))
			_add_by_dichotomie(nb, begin, half - 1);
		else
			_add_by_dichotomie(nb, begin + half + 1, half);
	}
	else if (length % 2 == 0)
	{
		if (nb < *(begin + half))
			_add_by_dichotomie(nb, begin, half - 1);
		else
			_add_by_dichotomie(nb, begin + half + 1, half - 1);
	}
}

int	PmergeMe::_get_first(std::pair<int, int> pair)
{
	return (pair.first);
}


void PmergeMe::_orderPairDecreasing(std::pair<int,int> &pair)
{
	if (pair.first < pair.second)
		std::swap(pair.first, pair.second);
}


void PmergeMe::_createPairs()
{
	for (intdequeIt_t it = _originalDeque.begin(); it != _originalDeque.end(); it+=2)
	{
		if (it + 1 == _originalDeque.end())
			break ;
		_pairDeque.push_back(std::make_pair(*it, *(it + 1)));
	}
}

intDeque_t PmergeMe::_sortOneElement(intDeque_t& originalDeque)
{
	intDeque_t returndeque(1, *originalDeque.begin());
	return (returndeque);
}

/*Cree la suite de Jacobsthal jusqu'au int max a la fin.*/
void	PmergeMe::_createJacobsthalDeque(unsigned long nmoins2, unsigned long nmoins1)
{
	if (nmoins1 == 1 && nmoins2 == 1)
	{
		PmergeMe::jacobsthalSuit.push_back(1);
		PmergeMe::jacobsthalSuit.push_back(1);
	}
	unsigned long n = 2 * nmoins2 + nmoins1;
	if (n >= static_cast<unsigned long>(std::numeric_limits<int>::max()))
	{
		jacobsthalSuit.push_back(std::numeric_limits<int>::max());
		return ;
	}

	jacobsthalSuit.push_back(n);
	
	_createJacobsthalDeque(nmoins1, n);
}

void	PmergeMe::_nextNumberJacob(int & nb)
{
	nb--;
	/*Si on a un nombre qui existe dans jac
	Alors on renvoie celui de l'index d'apres*/
	 std::deque<int>::iterator found = std::find(jacobsthalSuit.begin(), jacobsthalSuit.end(), nb);
	if (found != jacobsthalSuit.end())
	{
		found+=2;
		nb = *found;
	}
	else if (nb == -1)
		nb = 3;
}

int	PmergeMe::_jacobOffset(int const &nb)
{
	if (nb == 0)
		return (3);
	std::deque<int>::iterator found = std::find(jacobsthalSuit.begin(), jacobsthalSuit.end(), nb - 1);

	if (found != jacobsthalSuit.end())
	{
		found = found + 2;
		return (*found - nb);
	}
	else
		return (-1);
}
// 1 0 3 2 
// // 
// // 1 1 3 5 11 23
// 12
// 12 + x = *(it +1)
// 1 0 3 2

int	PmergeMe::_is_in_jacob(int nb)
{
	int i = 0;
	
	for (intdequeIt_t it = jacobsthalSuit.begin(); it != jacobsthalSuit.end(); it++)
	{
		if (nb == *it)
			return (i);
		i++;
	}
	return (-1);
}


// void	PmergeMe::buildJacNumberSuit()
// {
// 	// std::cout << "voila le next nomber jacob : \n";
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	// _nextNumberJacob(nb);
// 	// std::cout << nb << " ";
// 	int nb = 3;
// 	std::pair<int, int> paire;
// 	while (nb != -1)
// 	{
// 		paire.first = nb;
// 		_nextNumberJacob(nb);
// 		paire.second = nb;
// 		std::cout << nb << " ";
// 		if (nb == -1)
// 			break ;
// 		jacNumberSuit.insert(paire);
// 	}
// }
