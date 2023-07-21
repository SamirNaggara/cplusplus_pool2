/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:45:40 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 14:15:13 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"



int	main()
{
	Data *data1 = new Data("Pierre qui roule n'amasse pas mousse");
	std::cout << "Voila le pointeur data normal : " << data1 << std::endl << std::endl;

	// On sérialise
	uintptr_t serialData = Serializer::serialize(data1);
	std::cout << "Voila le pointeur data serialisé : " << serialData << std::endl << std::endl;

	// On désérialise
	Data *data2 = Serializer::deserialize(serialData);
	std::cout << "Voila le pointeur data serialisé : " << data2 << std::endl << std::endl;

	if (data1 == data2)
		std::cout << "Bravo, la serialisation pour deserialisation mene bien vers la même adresse ! : " << data2 << std::endl << std::endl;


	delete data1;

	return (0);
}