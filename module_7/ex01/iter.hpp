/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:46:18 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/23 00:33:04 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER__
#define __ITER__

#include <cstddef>
#include <cmath>

template<typename T, typename U>
void	iter(T *tab, size_t size, U(&f)(T&))
{
	for (size_t i; i < size; i++)
		(*f)(tab[i]);
}

template<typename T>
void	add_one(T &var)
{
	var++;
}

void	inverseBool(bool &var)
{
	var = !var;
}


/*Cette fonction sert a prouvé que meme 
si on utilise une fonction qui a une valeur de retour avec Iter, ça marche*/
/* Arrondis le nombre, renvoie true s'il a changé*/
bool	round_sam(double &nb)
{
	double tmp = nb;
	nb = round(nb);
	if (nb != tmp)
		return (true);
	return (false);
}

#endif