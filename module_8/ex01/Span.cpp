/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:34:44 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/24 15:41:59 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int max) : 
	_max(max)
	{}

Span::Span(Span const& otherSpan) : 
	_max(otherSpan._max)
{
    for (t_span_it it = otherSpan._span_list.begin(); it != otherSpan._span_list.end(); ++it) {
        _span_list.insert(*it);
    }
}


Span&			Span::operator=(Span const& otherSpan)
{
	_max = otherSpan._max;
	for (t_span_it it = otherSpan._span_list.begin(); it != otherSpan._span_list.end(); ++it) {
		_span_list.insert(*it);
	}
	return (*this);
}


void			Span::addNumber(unsigned int nb)
{
	if (_span_list.size() >= _max)
		throw reachMaxElement();
	_span_list.insert(nb);
}


unsigned int	Span::shortestSpan() const
{
	if (_span_list.size() <= 1)
		throw NotEnoughNumbers();

	unsigned int short_span;
	unsigned int span;
	t_span_it it;
	t_span_it left;

	short_span = *(_span_list.end()) - *(_span_list.begin());
	for (it = _span_list.begin(); it != _span_list.end();) {
		left = it;
		it++;
		if (it == _span_list.end())
			break;
		span = *it - *left;
		short_span = (short_span < span) ? short_span : span;
	}
	return (short_span);
}

unsigned int	Span::longestSpan() const
{
	if (_span_list.size() <= 1)
		throw NotEnoughNumbers();
	return (*(_span_list.rbegin()) - *(_span_list.begin()));

}


