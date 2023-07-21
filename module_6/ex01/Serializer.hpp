/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:32:07 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 14:11:54 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	__SERIALIZER__
# define 	__SERIALIZER__

# include <stdint.h>
# include <iostream>

# include "Data.hpp"

class Serializer
{
private:
	Serializer(void);
	Serializer(Serializer const& serial);
	Serializer&	operator=(Serializer const& serial);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* 	deserialize(uintptr_t raw);
};


#endif
