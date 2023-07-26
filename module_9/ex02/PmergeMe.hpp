/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:22:51 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/26 15:26:39 by snaggara         ###   ########.fr       */
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

#include <vector>
#include <exception>

typedef std::vector<int> intVector_t;
typedef intVector_t::iterator intVectorIt_t;
typedef std::vector<std::pair<int, int> > pairVector_t;
typedef pairVector_t::iterator pairVectorIt_t;

class PmergeMe
{

	PmergeMe();
	PmergeMe(PmergeMe const& other);
	PmergeMe&	operator=(PmergeMe const& other);

	static intVector_t _sortOneElement(intVector_t& originalVector);

	static pairVector_t	_createPairs(intVector_t & originalVector);

	static void _orderPairDecreasing(std::pair<int,int> &pair);

	static int	_found_second(int const &nb, pairVector_t &pairs);
	
	static int	_get_second(std::pair<int, int> pair);
public:
	~PmergeMe(){};

	static intVector_t	mergeSort(intVector_t& originalVector);

	class FirstNotFound : public std::exception
	{
		public:
			const char * what() const throw()
			{
				return "FirstNotFount error : You try to found the second element using a first element of the pair, but the first element doesn't exist";
			}
	};
};




#endif