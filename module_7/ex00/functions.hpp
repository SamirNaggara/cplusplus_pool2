/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:34:32 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/22 23:43:43 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FUNCTIONS__
#define __FUNCTIONS__

template<typename T>
void	swap(T &t1, T &t2)
{
	T tmp = t1;

	t1 = t2;
	t2 = tmp;
}

template<typename T>
T&	min(T &t1, T &t2)
{
	if (t1 < t2)
		return t1;
	return t2;
}

template<typename T>
T&	max(T &t1, T &t2)
{
	if (t1 > t2)
		return t1;
	return t2;
}


#endif