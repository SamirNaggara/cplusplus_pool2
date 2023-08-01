/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:36:45 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/01 03:31:15 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"


queueChar_t createRpnQueue(int ac, char ** & av)
{
	queueChar_t rpnInput;
	std::cout << "Voila ac: " << ac << "\n";

	for (int i = 1; i < ac; i++)
	{
		std::cout << "char en creation : " << av[i][0] << "\n";
		rpnInput.push(av[i][0]);
	}
	return (rpnInput);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Pas d'arguments, on veut des arguments\n";
		return (0);
	}

	try{
		queueChar_t rpnInput = ::createRpnQueue(ac, av);

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