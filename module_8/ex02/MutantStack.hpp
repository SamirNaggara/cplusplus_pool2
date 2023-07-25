/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/25 11:42:01 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK__
#define __MUTANT_STACK__

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator    iterator;
	MutantStack(){};
	~MutantStack(){};
	MutantStack(MutantStack const& other) : std::stack<T, Container>(other)
	{}
	MutantStack&	operator=(MutantStack const& other)
	{
		std::stack<T, Container>::operator=(other);
		return (*this);
	}
	typename MutantStack::iterator	begin()
	{
		return this->c.begin();
	}
	typename MutantStack::iterator	end()
	{
		return this->c.end();
	}
};

/*::c permet d'acceder au contener de l'element*/






#endif