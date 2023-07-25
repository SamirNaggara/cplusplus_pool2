/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:25:13 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/24 15:43:41 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN__
#define __SPAN__

#include <set>
#include <vector>
#include <exception>


typedef std::set<unsigned int> t_span_set;
typedef t_span_set::iterator t_span_it;
typedef std::vector<unsigned int> t_vector;
typedef t_vector::iterator t_vector_it;


class Span
{
private:
	unsigned int _max;
	t_span_set _span_list;
	Span(){};

public:
	Span(unsigned int max);
	Span(Span const& otherSpan);
	~Span(){};
	Span&			operator=(Span const& otherSpan);

	void			addNumber(unsigned int nb);

	template <typename I>
	void			addNumbers(I beg, I end);
	
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;


	class reachMaxElement : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "\033[31mReachMaxElement error : Max size of class Span is reach\"\033[0m";
			}
	};

	class NotEnoughNumbers : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "\033[31mNotEnoughNumbers error : With 0 or 1 number, it is not possible to found shortest or longuest span\"\033[0m";
			}
	};
};

/* Fait sous forme de template pour accepter
différents conteneurs*/
template<typename I>
void	Span::addNumbers(I beg, I end)
{
	for (I it = beg; it != end; it++)
		addNumber(*it);
}

#endif
