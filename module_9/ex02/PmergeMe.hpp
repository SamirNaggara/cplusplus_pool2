/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:51 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/01 11:32:10 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Etape 1 : Faire en sorte que si la liste envoyée est un seul nombre, renvoie le nombre
	Etape 2 : Imaginons qu'on reçois les infos sous forme de list. Test que ça marche avec un seul élément
	Etape 3 : Creer une list de pairs (first, second)
	Etape 4 : Trier la list pour que first soit le premier
	Etape : Creer une sous liste avec seulement les nombres plus élévés, un copy if ou avec transform
	Etape 5: Appeler de manière recursive merge_sort.
	Etape 6 : Passer par tout les "seconds" des pairs, et les inserer dans la liste un par un par dichotomie !
	Etape 7 : Verifier que tout marche bien !







	Etape 8: Ajoute une variable pour compter le nombre de comparaisons
	Etape 9: Ajoute le calcul du temps en sortie

	Etape 10: creer une fonction qui a chaque appel est capable de donner le nombre suivant de la suite de Jacobsthal (peut etre la version modifier de Jacobsthal car le premier on l'ajoute sans comparaison)
	Etape 10: Ajouter l'optimisation des nombres de Jacobsthal
	En gros la fonct
*/

#ifndef __PMERGE_ME__
# define __PMERGE_ME__

#include <deque>
#include <vector>
#include <map>
#include <exception>
#include <iostream>
#include <utility>
#include <algorithm>
#include <limits>
#include <sys/time.h>

typedef std::deque<int> intDeque_t;
typedef intDeque_t::iterator intdequeIt_t;

typedef std::vector<int> intVector_t;
typedef intVector_t::iterator intVectorIt_t;

typedef std::deque<std::pair<int, int> > pairDeque_t;
typedef pairDeque_t::iterator pairDequeIt_t;

template<typename T>
class PmergeMe
{

	pairDeque_t 	_pairDeque;
	T 				_originalDeque;
	T 				_firstPairDeque;
	T 				_secondPairDeque;
	int				_maxI;
	intDeque_t		_jacobsthalSuit;
	struct timeval	_start;
	struct timeval	_end;



	PmergeMe(void);
	PmergeMe(PmergeMe const& other);
	PmergeMe<T>&		operator=(PmergeMe const& other);

	T	 			_sortOneElement(T& originalDeque);
	void			_createPairs();
	static void 	_orderPairDecreasing(std::pair<int,int> &pair);
	static int		_get_first(std::pair<int, int> pair);
	void			_addSecondElementsWithJacob();
	void			_add_by_dichotomie(int nb, typename T::iterator begin, int length);
	void			_sortEachPair();
	void			_createFirstPairDeque();
	void			_createSecondPairDeque();
	void			_addLastIfOdd();


	void			_createJacobsthal(unsigned long nmoins1, unsigned long nmoins2);
	void			_nextNumberJacob(int & nb);
	int				_jacobOffset(int const &nb);

public:
	PmergeMe(intDeque_t& originalDeque);
	PmergeMe(intVector_t& originalDeque);
	~PmergeMe(){};

	T			mergeSort();
	void		buildJacNumberSuit();
	void		_advanceCursor(int &i, typename T::iterator &itD2, int &length);
	double		getOperationTime() const;


	class FirstNotFound : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "PmergeMe::FirstNotFound error : You try to found the second element using a first element of the pair, but the first element doesn't exist";
			}
	};

	class DuplicateNumbers : public std::exception
	{
		public:
		int		nb;
		DuplicateNumbers(int nb) : nb(nb){};
			const char * what() const throw()
			{
				return "PmergeMe::DuplicateNumbers error : No duplicate number should be allow with PmergeMe";
			}
	};

	/*Ceci est un foncteur
	Il sert a creer un deque avec les seconds pairs
	Mais en se basant sur le bon ordre
	*/
	struct GetSecond
	{
	private:
		pairDeque_t 	_pairDeque;

	public:
		GetSecond(pairDeque_t &pairDeque)
			: _pairDeque(pairDeque)
			{}
		int operator()(int const& nb)
		{
			for (pairDequeIt_t it = _pairDeque.begin(); it != _pairDeque.end(); it++)
			{
				if (it->first == nb)
					return (it->second);
			}
			throw PmergeMe::FirstNotFound();
		}

	};
};

#include "PmergeMe.cpp"


template <typename T>
PmergeMe<T>::PmergeMe(){};

/*A la construction, on initialise statiquement le jacobien, si il n'existe pas*/
template <typename T>
PmergeMe<T>::PmergeMe(intDeque_t& originalDeque)
	:_originalDeque(originalDeque)
{
    gettimeofday(&_start, NULL);
	
	if (_jacobsthalSuit.size() == 0)
	{
		_createJacobsthal(1, 1);
		_jacobsthalSuit.pop_front();
		_jacobsthalSuit.push_back(-1);
	}
};

template <typename T>
PmergeMe<T>&	PmergeMe<T>::operator=(PmergeMe const& other)
{
	static_cast<void>(other);
	return (*this);
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const& other)
	{(void)other;}


template <typename T>
T	PmergeMe<T>::mergeSort()
{
	if (_originalDeque.size() == 1)
		return _sortOneElement(_originalDeque);

	_createPairs();
	_sortEachPair();
	_createFirstPairDeque();
	PmergeMe<T> merge(_firstPairDeque);
	_firstPairDeque = merge.mergeSort();
	_createSecondPairDeque();
	_addSecondElementsWithJacob();
	_addLastIfOdd();
	gettimeofday(&_end, NULL);
	return (_firstPairDeque);
}

template <typename T>
void	PmergeMe<T>::_createSecondPairDeque()
{
	GetSecond getSecond(_pairDeque);
	std::transform(_firstPairDeque.begin(), _firstPairDeque.end(), std::back_inserter(_secondPairDeque), getSecond);
}

template <typename T>
void	PmergeMe<T>::_createFirstPairDeque()
{
	std::transform(_pairDeque.begin(), _pairDeque.end(), std::back_inserter(_firstPairDeque), _get_first);
}

template <typename T>
void	PmergeMe<T>::_sortEachPair()
{
	std::for_each(_pairDeque.begin(), _pairDeque.end(), _orderPairDecreasing);
}

template <typename T>
void	PmergeMe<T>::_addSecondElementsWithJacob()
{
	typename T::iterator itD2 = _secondPairDeque.begin();

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

template <typename T>
void	PmergeMe<T>::_advanceCursor(int &i, typename T::iterator &itD2, int &length)
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

template <typename T>
void	PmergeMe<T>::_addLastIfOdd()
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
template <typename T>
void	PmergeMe<T>::_add_by_dichotomie(int nb, typename T::iterator begin, int length)
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

template <typename T>
int	PmergeMe<T>::_get_first(std::pair<int, int> pair)
{
	return (pair.first);
}

template <typename T>
void PmergeMe<T>::_orderPairDecreasing(std::pair<int,int> &pair)
{
	if (pair.first < pair.second)
		std::swap(pair.first, pair.second);
}

template <typename T>
void PmergeMe<T>::_createPairs()
{
	for (typename T::iterator it = _originalDeque.begin(); it != _originalDeque.end(); it+=2)
	{
		if (it + 1 == _originalDeque.end())
			break ;
		_pairDeque.push_back(std::make_pair(*it, *(it + 1)));
	}
}

template <typename T>
T PmergeMe<T>::_sortOneElement(T& originalDeque)
{
	T returndeque(1, *originalDeque.begin());
	return (returndeque);
}

/*Cree la suite de Jacobsthal jusqu'au int max a la fin.*/
template <typename T>
void	PmergeMe<T>::_createJacobsthal(unsigned long nmoins2, unsigned long nmoins1)
{
	if (nmoins1 == 1 && nmoins2 == 1)
	{
		PmergeMe<T>::_jacobsthalSuit.push_back(1);
		PmergeMe<T>::_jacobsthalSuit.push_back(1);
	}
	unsigned long n = 2 * nmoins2 + nmoins1;
	if (n >= static_cast<unsigned long>(std::numeric_limits<int>::max()))
	{
		_jacobsthalSuit.push_back(std::numeric_limits<int>::max());
		return ;
	}

	_jacobsthalSuit.push_back(n);
	
	_createJacobsthal(nmoins1, n);
}

template <typename T>
void	PmergeMe<T>::_nextNumberJacob(int & nb)
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

template <typename T>
int	PmergeMe<T>::_jacobOffset(int const &nb)
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

template <typename T>
double	PmergeMe<T>::getOperationTime() const
{
	long diffSeconds = _end.tv_sec - _start.tv_sec;
    long diffMicroseconds = _end.tv_usec - _start.tv_usec;
	double diff = diffSeconds + diffMicroseconds * 1e-6;
	return (diff);
}


/* Adaptation pour le vector */

/*A la construction, on initialise statiquement le jacobien, si il n'existe pas*/
template <typename T>
PmergeMe<T>::PmergeMe(intVector_t& originalDeque)
	:_originalDeque(originalDeque)
{
    gettimeofday(&_start, NULL);
	
	if (_jacobsthalSuit.size() == 0)
	{
		_createJacobsthal(1, 1);
		_jacobsthalSuit.pop_front();
		_jacobsthalSuit.push_back(-1);
	}
};

template <>
void	PmergeMe<intVector_t>::_addSecondElementsWithJacob()
{
	typename intVector_t::iterator itD2 = _secondPairDeque.begin();

	_firstPairDeque.insert(_firstPairDeque.begin(), *itD2);
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

#endif
