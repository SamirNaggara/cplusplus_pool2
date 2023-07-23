/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:39:16 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/23 02:13:00 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY__
#define __ARRAY__

#include <stdexcept>

template<typename T>

class Array
{
private:
	T	*_m_array;
	unsigned int _m_size;
public:
	Array(void);
	Array(unsigned int n);
	Array(Array const& otherArray);
	~Array();
	Array<T>&	operator=(Array const& otherArray);

	unsigned int 	size() const;
	T				*get_array();
	void			display() const;

	T&	operator[](unsigned int n) const;


};

template<typename T>
Array<T>::Array(void) : _m_size(0)

{
	_m_array = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n) : _m_size(n)
{
	_m_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_m_array[i] = 0;
}

	
template<typename T>
Array<T>::~Array()
{
	delete [] _m_array;
}


template<typename T>
Array<T>::Array(Array const& otherArray) : _m_size(otherArray._m_size)
{
	_m_array = new T[_m_size];
	for (unsigned int i = 0; i < _m_size; i++)
		_m_array[i] = otherArray._m_array[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(Array const& otherArray)
{
	_m_size = otherArray._m_size;
	delete [] _m_array;

	for (unsigned int i = 0; i < _m_size; i++)
		_m_array[i] = otherArray._m_array[i];
	return (*this);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (_m_size);
}

template<typename T>
void			Array<T>::display() const
{
	for (unsigned int i = 0; i < _m_size; i++)
		std::cout << "Element " << i << " : " << (*this)[i] << std::endl;
	std::cout << std::endl;
	
}

template<typename T>
T&	Array<T>::operator[](unsigned int n) const
{
	if (n >= _m_size)
		throw std::length_error("Invalid Index : Superior to max length");
	return (_m_array[n]);
}

template<typename T>

T	*Array<T>::get_array()
{
	return (_m_array);
}

#endif