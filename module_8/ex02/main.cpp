/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:22:31 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/25 11:40:21 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <string>
#include <vector>
#include <list>

int	main()
{
	std::cout << "On crée la stack\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "On ajoute 5 et 17, et on regarde l'élément en haut\n";

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Maintenant on a supprimé le dernier element, et on regarde la taille de la stack\n";
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Ajoutons 3,5,737 et 0, puis utilisons des itérateurs pour parcourir toute la stack\n";

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "On copie la liste grace au constructeur de copie, on supprime le dernier element de la copie, puis on regarde les 2\n";
	
	MutantStack<int> copieStack(mstack);
	copieStack.pop();
	std::cout << "L'original :\n";

	MutantStack<int>::iterator it2 = mstack.begin();

	while (it2 != ite)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << "La copie :\n";

	MutantStack<int>::iterator it3 = copieStack.begin();
	MutantStack<int>::iterator ite3 = copieStack.end();

	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	std::cout << "\n\nTestons l'opérateur d'affectation, puis ajoutons un element à la copie\n";
	MutantStack<int> emptyStack;

	emptyStack = mstack;
	emptyStack.push(456);

		std::cout << "Affichons l'original :\n";

	MutantStack<int>::iterator it4 = mstack.begin();

	while (it4 != ite)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}

	std::cout << "Puis la copie :\n";

	MutantStack<int>::iterator it5 = copieStack.begin();
	MutantStack<int>::iterator ite5 = copieStack.end();

	while (it5 != ite5)
	{
		std::cout << *it5 << std::endl;
		++it5;
	}



	std::cout << "\n\nOn crée une stack de string, puis on l'affiche avec les iterators\n";
	MutantStack<std::string> str_stack;

	str_stack.push("Salut");
	str_stack.push("ça");
	str_stack.push("va");

	MutantStack<std::string>::iterator it6 = str_stack.begin();
	MutantStack<std::string>::iterator ite6 = str_stack.end();
	while (it6 != ite6)
	{
		std::cout << *it6 << std::endl;
		++it6;
	}

	std::cout << "\n\nOn crée une stack de double, puis on parcours avec les iterateurs\n";
	MutantStack<double> double_stack;

	double_stack.push(35.25);
	double_stack.push(50);
	double_stack.push(3.12);

	MutantStack<double>::iterator it7 = double_stack.begin();
	MutantStack<double>::iterator ite7 = double_stack.end();
	while (it7 != ite7)
	{
		std::cout << *it7 << std::endl;
		++it7;
	}
	return (0);
}