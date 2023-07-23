/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:43:20 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/23 02:20:36 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main()
{
	try{
		// Test avec int
		Array<int> arrObj(5);

		std::cout << "Voila le nombre d'elements du tableau : " << arrObj.size() << std::endl << std::endl;
		// On affiche tout les elements avec crochet
		std::cout << "On affiche tout le tableau" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "Element " << i << " : " << arrObj[i] << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	try{
		Array<int> arrObj(5);
		// L'opérateur [] marche bien
		arrObj[3] = 8;

		// On affiche tout les elements avec crochet
		std::cout << "On réaffiche tout le tableau, cette fois en voyant la modificaiton" << std::endl;

		for (int i = 0; i < 5; i++)
			std::cout << "Element " << i << " : " << arrObj[i] << std::endl;
		std::cout << std::endl;
	}catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}

	try{
		Array<int> arrObj(5);
		// L'opérateur [] marche bien
		arrObj[3] = 8;

		std::cout << "Premier tableaux de int" << std::endl;

		arrObj.display();
		std::cout << std::endl;

		// On affiche tout les elements avec crochet
		std::cout << "On fait une copie du tableau, qu'on affiche" << std::endl;

		Array<int> copie(arrObj);
		copie.display();
		std::cout << std::endl;

		std::cout << "On modifie la copie, l'original n'est pas perturbé" << std::endl << std::endl;
		copie[1] = 123;
		std::cout << "L'original" << std::endl;
		arrObj.display();
		std::cout << "La copie" << std::endl;
		copie.display();



	}catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}

	try{
		Array<int> arrObj(5);
		// L'opérateur [] marche bien
		arrObj[3] = 8;
		arrObj[1] = 2;
		arrObj[0] = 4;

		std::cout << "Premier tableaux de int, qu'on modifie un peu" << std::endl;

		arrObj.display();
		std::cout << std::endl;

		// On affiche tout les elements avec crochet
		std::cout << "On cree un deuxieme tableau par affectation" << std::endl;
		Array<int> arrObj2 = arrObj;
		arrObj2.display();

		
		std::cout << "On modifie le deuxieme tableau, le premier s'en fout" << std::endl;
		arrObj2[4] = 456;
		std::cout << "L'original" << std::endl;
		arrObj.display();
		std::cout << "La copie" << std::endl;
		arrObj2.display();



	}catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}

	try{
		std::cout << "Tableau vide : Essayons d'atteindre l'élément 0" << std::endl;
		Array<int> arrObj;

		std::cout << arrObj[0] << std::endl;


	}
	catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}

	try{
		std::cout << std::endl;
		std::cout << std::endl;

		// Test avec int
		Array<double> arrObj(5);

		arrObj[0] = 1.85;
		arrObj[1] = 89.8525;
		arrObj[2] = -135.20;
		// On affiche tout les elements avec crochet
		std::cout << "On affiche tout le tableau de double" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "Element " << i << " : " << arrObj[i] << std::endl;
		std::cout << std::endl;


	}
	catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}

	try{
		std::cout << std::endl;
		std::cout << std::endl;

		// Test avec int
		Array<char> arrObj(5);

		arrObj[0] = 'S';
		arrObj[1] = 'A';
		arrObj[2] = 'L';
		// On affiche tout les elements avec crochet
		std::cout << "On affiche tout le tableau de char" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "Element " << i << " : " << arrObj[i] << std::endl;
		std::cout << std::endl;


	}
	catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}

	try{
		std::cout << std::endl;
		std::cout << std::endl;

		// Test avec int
		Array<bool> arrBool(5);

		arrBool[0] = false;
		arrBool[1] = true;
		arrBool[2] = true;
		// On affiche tout les elements avec crochet
		std::cout << "Tableau de booleen" << std::endl;
		for (int i = 0; i < 6; i++)
			std::cout << "Element " << i << " : " << arrBool[i] << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m"<< std::endl;
	}
}