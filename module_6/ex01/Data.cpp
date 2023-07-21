/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:43:12 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 14:07:55 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Data.hpp"
#include <iostream>


Data::Data(std::string const sentence) :
	m_sentence(sentence)
{
	//std::cout << "Le constructeur de Data est bien appelé" <<std::endl;
}

Data::Data(Data const& data)
{
	m_sentence = data.m_sentence;
}
Data::~Data(){
	//std::cout << "Le destructeur de Data est bien appelé" <<std::endl;

};

Data&	Data::operator=(Data const& data)
{
	m_sentence = data.m_sentence;
	return (*this);
}