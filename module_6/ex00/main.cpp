/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:52:45 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/20 15:05:38 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: nb arguement\nTry that : ./scalarConvertor arg" << std::endl;
		return (0);
	}
	try{
		ScalarConverter::convert(av[1]);

	}
	catch(std::exception const& e){
		std::cout << e.what() << std::endl;
	}
}