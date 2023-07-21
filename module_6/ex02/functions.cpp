/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:39:33 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 15:43:48 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"



Base	*generate(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	std::srand(tv.tv_usec);

	int randomNumber = std::rand() % 3;
	if (randomNumber == 0)
	{
		std::cout << "generate : Je viens de creer un A" << std::endl;
		return (new A());
	}
	else if (randomNumber == 1)
	{
		std::cout << "generate : Je viens de creer un B" << std::endl;
		return (new B());
	}
	else if (randomNumber == 2)
	{
		std::cout << "generate : Je viens de creer un C" << std::endl;
		return (new C());
	}
	else
		throw std::range_error("Le nombre aléatoire n'a pas correctement été généré : " + randomNumber);
	
}

void	identify(Base & p)
{
	try{
		dynamic_cast<A&>(p);
	}catch(std::exception const& e)
	{
		try{
			dynamic_cast<B&>(p);
		}catch(std::exception const& e)
		{
			try{
				dynamic_cast<C&>(p);
			}catch(std::exception const& e)
			{
				std::cout << "identify& : Ni A, ni B, ni c !" << std::endl;
				return ;
			}
			std::cout << "identify& : Bon, bah c'est une classe C" << std::endl;
			return ;
		}
		std::cout << "identify& : Ok, on est sur une banal class B" << std::endl;
		return ;
		
	}
	std::cout << "identify& : Ok, on est sur de la belle class A là" << std::endl;
	return ;
}

/*
	Le try catch fonctionne aussi avec les pointeurs, super !
*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "identify* : Ok, on est sur de la belle class A là" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identify* : Ok, on est sur une banal class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identify* : Bon, bah c'est une classe C" << std::endl;
	else
		std::cout << "identify* : Ni A, ni B, ni c !" << std::endl;
}