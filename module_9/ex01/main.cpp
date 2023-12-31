/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:36:45 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/01 11:58:40 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"


queueChar_t createRpnQueue(char * &dataStr)
{
	queueChar_t rpnInput;

	int	i = 0;
	while (dataStr[i])
	{
		if (i % 2 == 1)
		{
			i++;
			continue ;
		}
		rpnInput.push(dataStr[i]);
		i++;
	}
	return (rpnInput);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Il faut exactement un argument, contenant tout les nombres de l'operation RPN\n";
		return (0);
	}

	try{
		queueChar_t rpnInput = ::createRpnQueue(av[1]);

		RPN	rpnIns(rpnInput);
		int resultat = rpnIns.calculate();
		std::cout << resultat;
	}
	catch (std::exception const& e)
	{
		std::cout << "\033[031m" << e.what() << "\033[0m" << std::endl;
	}
	return (0);

}