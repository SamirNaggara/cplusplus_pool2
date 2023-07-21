/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:54:40 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 14:09:01 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(Serializer const& serial)
{
	static_cast<Serializer>(serial);
}

Serializer&	Serializer::operator=(Serializer const& serial)
{
	static_cast<Serializer>(serial);
	return (*this);
}


uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);

}
