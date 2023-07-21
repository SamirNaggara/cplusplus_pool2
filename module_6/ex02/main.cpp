/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:06:30 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 15:47:23 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "functions.hpp"

int	main()
{
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl << std::endl << "Test " << i + 1 << " : " << std::endl;
		Base *random = generate();
		Base &randomRef = *random;
		identify(randomRef);
		identify(random);
	}
}