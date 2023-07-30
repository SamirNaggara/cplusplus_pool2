/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:51 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/30 23:01:26 by snaggara         ###   ########.fr       */
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

typedef std::deque<int> intDeque_t;
typedef intDeque_t::iterator intdequeIt_t;
typedef std::deque<std::pair<int, int> > pairDeque_t;
typedef pairDeque_t::iterator pairDequeIt_t;

class PmergeMe
{

	PmergeMe(PmergeMe const& other);
	PmergeMe&	operator=(PmergeMe const& other);

	intDeque_t _sortOneElement(intDeque_t& originalDeque);

	void	_createPairs();

	static void _orderPairDecreasing(std::pair<int,int> &pair);

	//int	_found_second(int const &nb);
	
	//static int	_get_second(int const& nb);
	static int	_get_first(std::pair<int, int> pair);

	void	_addSecondElements();
	void	_addSecondElementsWithJacob();

	void	_add_by_dichotomie(int nb, intdequeIt_t begin, int length);

	pairDeque_t 	_pairDeque;
	intDeque_t 		_originalDeque;
	intDeque_t 		_firstPairDeque;
	intDeque_t 		_secondPairDeque;

	int		_maxI;

	void	_sortEachPair();
	void	_createFirstPairDeque();
	void	_createSecondPairDeque();

	PmergeMe();

	void		_createJacobsthalDeque(unsigned long nmoins1, unsigned long nmoins2);
	void	_nextNumberJacob(int & nb);

	int	_is_in_jacob(int nb);

	//void	_jacobItOrder(int &i, intdequeIt_t &it);
	int		_jacobOffset(int const &nb);

	void	_addLastIfOdd();

// 1 2 3 4 6
// 1 3 5
//Au premier tour l == 3

// e3 e2 e1 1  2  3  4  5  6  7  8  10
//    e1 e2 e3 e4 e5
// Au premier tour l = 4
// Au deuxieme tour l = 3
// i = 2


// e1 e1 e2 e2 .. e5 e5
// Avec jacob
// e1 -> (manuel)
// e3 = l -> 2  (3)
// e2 = l -> 2
// e5 = l -> 6 (7)  2 * 3 + 1
// e4 = l -> 6
  // e6 = l = 2 * compteur  + 
// e11 = l -> 14 (15) 5 * 2 + 5
// e10 = l = 
// e9
// e8 
// e7 
// e6
// e21 -> l = 11 * 2 + 21 - 12 = 22 + 9 = 31
// e20

// 2^n - 1
// 1 1 3 5 11 21 
// Sans jacob
// i = 0 -> (manuel)
// i = 1 -> (manuel)
// i = 2 -> longueur 3
// i = 3 -> longueur 5
// i = 4 -> longueuer 7
// i = 5 -> longueuer 9
// i = 7 -> longueuer 11
// 1 2 3 6
// 0
// 1 0 3 2 5 4 11 10 9 8 
// 0

// 1 

// 2 3 4 5 6 7

// 8 .. 15



public:
	std::vector<int>	_jacobSuitNumbers;
	PmergeMe(intDeque_t& originalDeque);
	~PmergeMe(){};

	intDeque_t	jacobsthalSuit;

	intDeque_t	mergeSort();

	void	buildJacNumberSuit();
	void	_advanceCursor(int &i, intdequeIt_t &itD2, int &length);


	class FirstNotFound : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "FirstNotFound error : You try to found the second element using a first element of the pair, but the first element doesn't exist";
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



#endif

//(compteur) * 2 - missed
/*
indice 2 -> longueur 2
indice 4 -> longueur 6
indice 

*/