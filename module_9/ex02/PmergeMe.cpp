/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:47 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/30 23:55:23 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};

/*A la construction, on initialise statiquement le jacobien, si il n'existe pas*/
PmergeMe::PmergeMe(intDeque_t& originalDeque)
	:_originalDeque(originalDeque)
{
    gettimeofday(&_start, NULL);
	
	if (_jacobsthalSuit.size() == 0)
	{
		_createJacobsthalDeque(1, 1);
		_jacobsthalSuit.pop_front();
		_jacobsthalSuit.push_back(-1);
	}
};

PmergeMe&	PmergeMe::operator=(PmergeMe const& other)
{
	static_cast<void>(other);
	return (*this);
}

PmergeMe::PmergeMe(PmergeMe const& other)
	{(void)other;}


intDeque_t	PmergeMe::mergeSort()
{
	if (_originalDeque.size() == 1)
		return _sortOneElement(_originalDeque);

	_createPairs();
	_sortEachPair();
	_createFirstPairDeque();
	PmergeMe merge(_firstPairDeque);
	_firstPairDeque = merge.mergeSort();
	_createSecondPairDeque();
	_addSecondElementsWithJacob();
	_addLastIfOdd();
	gettimeofday(&_end, NULL);
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

void	PmergeMe::_addSecondElementsWithJacob()
{
	intdequeIt_t itD2 = _secondPairDeque.begin();

	_firstPairDeque.push_front(*itD2);
	if (_secondPairDeque.size() == 1)
		return ;
	itD2++;
	_add_by_dichotomie(*itD2, _firstPairDeque.begin(), 1);
	itD2--;
	if (_secondPairDeque.size() == 2)
		return ;

	int i = 0;
	size_t compteur = 2;
	int length = 2;
	_maxI = 1;

	while (compteur < _secondPairDeque.size())
	{
		compteur++;
		_advanceCursor(i, itD2, length);
		_add_by_dichotomie(*itD2, _firstPairDeque.begin(), length);								
	}
}

void	PmergeMe::_advanceCursor(int &i, intdequeIt_t &itD2, int &length)
{
		int offset = _jacobOffset(i);
		int nbMissed = 0;
		
		if (offset == -1)
		{
			itD2--;
			i--;
			return ;
		}
		
		for (int j = 0; j < offset; j++)
		{
			itD2++;
			i++;
			if (i > _maxI)
				nbMissed++;
			if (itD2 == _secondPairDeque.end())
			{
				i--;
				itD2--;
				nbMissed--;
				break ;
			}
		}
		length = 2 * i - nbMissed;
		nbMissed = 0;
		_maxI = i;
}

void	PmergeMe::_addLastIfOdd()
{
	if (_originalDeque.size() % 2 == 1)
	{
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
		else if (nb > *begin)
			_firstPairDeque.insert(begin + 1, nb);
		else
			throw DuplicateNumbers(nb);
	}
	else if (length == 1)
	{
		if (nb < *(begin + half))
			_add_by_dichotomie(nb, begin, half);
		else if (nb > *(begin + half))
			_add_by_dichotomie(nb, begin + 1, half);
		else
			throw DuplicateNumbers(nb);
	}
	else if (length % 2 == 1)
	{
		if (nb < *(begin + half))
			_add_by_dichotomie(nb, begin, half - 1);
		else if (nb > *(begin + half))
			_add_by_dichotomie(nb, begin + half + 1, half);
		else
			throw DuplicateNumbers(nb);
	}
	else if (length % 2 == 0)
	{
		if (nb < *(begin + half))
			_add_by_dichotomie(nb, begin, half - 1);
		else if (nb > *(begin + half))
			_add_by_dichotomie(nb, begin + half + 1, half - 1);
		else
			throw DuplicateNumbers(nb);
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
		PmergeMe::_jacobsthalSuit.push_back(1);
		PmergeMe::_jacobsthalSuit.push_back(1);
	}
	unsigned long n = 2 * nmoins2 + nmoins1;
	if (n >= static_cast<unsigned long>(std::numeric_limits<int>::max()))
	{
		_jacobsthalSuit.push_back(std::numeric_limits<int>::max());
		return ;
	}

	_jacobsthalSuit.push_back(n);
	
	_createJacobsthalDeque(nmoins1, n);
}

void	PmergeMe::_nextNumberJacob(int & nb)
{
	nb--;
	/*Si on a un nombre qui existe dans jac
	Alors on renvoie celui de l'index d'apres*/
	 std::deque<int>::iterator found = std::find(_jacobsthalSuit.begin(), _jacobsthalSuit.end(), nb);
	if (found != _jacobsthalSuit.end())
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
	std::deque<int>::iterator found = std::find(_jacobsthalSuit.begin(), _jacobsthalSuit.end(), nb - 1);

	if (found != _jacobsthalSuit.end())
	{
		found+=2;
		return (*found - nb);
	}
	else
		return (-1);
}

double	PmergeMe::getOperationTime() const
{
	long diffSeconds = _end.tv_sec - _start.tv_sec;
    long diffMicroseconds = _end.tv_usec - _start.tv_usec;
	double diff = diffSeconds + diffMicroseconds * 1e-6;
	return (diff);
}