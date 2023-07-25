/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:50:57 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/23 16:02:39 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <stack>
#include <list>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Pas assez d'argument, quelle nombre voulez vous chercher ?" << std::endl;
		return (0);
	}
	int	nb = std::atoi(av[1]);


	std::vector<int> tab_vector(100,0);
	FillArray fillStartZero(0);
	generate(tab_vector.begin(), tab_vector.end(), fillStartZero);

	//Afficher le vector
	std::cout << "Voici un vector : " << std::endl;
	for (std::vector<int>::iterator it = tab_vector.begin(); it != tab_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	std::cout << "Maintenans, trouvons l'élément demandé grace a notre foncitons " << std::endl;
	try {
		std::cout << *easyfind<std::vector<int> >(tab_vector, nb) << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "Nous n'avons pas trouvé l'élément dans la liste" << std::endl;
	}
	std::cout << std::endl;



	//test deque
	std::deque<int> tab_deque(100,0);
	generate(tab_deque.begin(), tab_deque.end(), fillStartZero);

	//Afficher le deque
	std::cout << std::endl << std::endl;
	std::cout << "Voici un deque : " << std::endl;
	for (std::deque<int>::iterator it = tab_deque.begin(); it != tab_deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	std::cout << "Maintenans, trouvons l'élément demandé grace a notre foncitons " << std::endl;
	try {
		std::cout << *easyfind<std::deque<int> >(tab_deque, nb) << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "Nous n'avons pas trouvé l'élément dans la liste" << std::endl;
	}
	std::cout << std::endl;




	//test list
	std::list<int> tab_list(100,0);
	generate(tab_list.begin(), tab_list.end(), fillStartZero);
	//Afficher le list
	std::cout << std::endl << std::endl;
	std::cout << "Voici une list : " << std::endl;
	for (std::list<int>::iterator it = tab_list.begin(); it != tab_list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	std::cout << "Maintenans, trouvons l'élément demandé grace a notre foncitons " << std::endl;
	try {
		std::cout << *easyfind<std::list<int> >(tab_list, nb) << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "Nous n'avons pas trouvé l'élément dans la liste" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}