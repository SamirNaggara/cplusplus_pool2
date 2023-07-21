/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:45:53 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 15:33:52 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FONCTIONS__
# define __FONCTIONS__

#include "Base.hpp"
#include <math.h>
#include <cstdlib>
#include <sys/time.h>
#include <exception>
#include <stdexcept>
#include <iostream>

Base	*generate(void);
void	identify(Base & p);
void identify(Base* p);

#endif