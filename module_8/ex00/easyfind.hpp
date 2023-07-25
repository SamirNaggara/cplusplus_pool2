/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:34:25 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/24 12:58:34 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND__
#define __EASYFIND__

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T & v, int const nb)
{
	typename T::iterator found = std::find(v.begin(), v.end(), nb);
	if (found == v.end())
		throw std::runtime_error("Not found");
	return (found);
}

/* Ceci est un foncteur qui permet de remplir d'entiers consecutifs un container*/
class FillArray
{
	int	_value;
	public:
		FillArray(int start) : _value(start){};

	int	operator()()
	{
		return (_value++);
	}
};

#endif