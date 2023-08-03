/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:22:40 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/03 15:09:03 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& otherBE)
	:_exchangeRate(otherBE._exchangeRate)
{}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& otherBE)
{
	_exchangeRate = otherBE._exchangeRate;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const char * dataFileName)
{
	std::ifstream 	flux;
	std::string 	line;
	pairMap_t		pair;
	size_t			posDelimiter;
	int				i = 2;

	flux.open(dataFileName);
	if (!flux)
		throw InvalidDataFile();
	getline(flux, line);
	while (getline(flux, line))
	{
		posDelimiter = line.find(",");
		if (posDelimiter == std::string::npos)
			throw	HandleDataError("Error : No delimiter in one line of data !", i);
		pair.first = line.substr(0, posDelimiter);
		_checkValidDate(pair.first, i);
		_checkValidNumber(line.substr(posDelimiter + 1), i);
		std::istringstream ss(line.substr(posDelimiter + 1));
		ss >> pair.second;
		_exchangeRate.insert(pair);
		i++;
	}
}

void	BitcoinExchange::_checkValidNumber(std::string const& number, int i)
{
	int	nbDot = 0;

	if (number.length() == 0)
		throw	HandleDataError("Error : Values is not valid !", i);

	size_t	j = 0;
	if (number[j] == '-')
		j++;
	for (; j < number.length(); j++)
	{
		if (number[j] == '.')
		{
			nbDot++;
			continue ;
		}
		if (number[j] < '0' || number[j] > '9')
			throw	HandleDataError("Error : Values is not valid !", i);

	}
	if (nbDot > 1)
		throw	HandleDataError("Error : Values is not valid !", i);
}

void	BitcoinExchange::_checkValidDate(std::string const& date, int i)
{
	std::string errorMessage = "Error : Date in data is not valid !" + date;
	if (date.length() != 10)
		throw	HandleDataError(errorMessage , i);
	if (date[4] != '-' || date[7] != '-')
		throw	HandleDataError(errorMessage, i);
	for (size_t j = 0; j != date.length(); j++)
	{
		if (j == 4 || j == 7)
			continue ;
		if (date[j] < '0' || date[j] > '9')
			throw	HandleDataError(errorMessage, i);
	}
}

void	BitcoinExchange::setInputData(const char * inputDataName)
{
	std::ifstream 	flux;
	std::string		line;
	size_t			posDelimiter;
	pairMap_t		pair;
	int				i = 2;

	flux.open(inputDataName);
	if (!flux)
		throw InvalidInputFile();
		
	getline(flux, line);
	while (getline(flux, line))
	{
		std::string errorMessage = "Error : No delimiter => " + line;
		try{
			posDelimiter = line.find("|");
			if (posDelimiter == std::string::npos)
				throw	HandleDataError(errorMessage, -1);
			pair.first = line.substr(0, posDelimiter - 1);
			_checkValidDate(pair.first, -1);
			_checkValidNumber(line.substr(posDelimiter + 2), -1);
			
			std::istringstream iss(line.substr(posDelimiter + 2));
			iss >> pair.second;
			_checkRangeNumber(pair.second);
			_inputData.push_back(pair);
		}
		catch(std::exception const& e)
		{
			pair.first = std::string(e.what());
			_inputData.push_back(pair);
		}
		i++;
	}
}

void	BitcoinExchange::_checkRangeNumber(float const& number)
{
	if (number < 0)
		throw	HandleDataError("Error : Number is negative", -1);
	if (number > 1000)
		throw	HandleDataError("Error : Number is greater than 1000", -1);
}

void	BitcoinExchange::calculateInput()
{
	for (listStrInt_t::iterator it = _inputData.begin(); it != _inputData.end(); it++)
	{
		if (it->first.substr(0, 5) == "Error")
			std::cout << it->first << std::endl;
		else
		{
			float value = _getBtcValue(it);
			std::cout << it->first << " => " << it->second << " = " << value << "\n";
			
		}
	}
	
}

float		BitcoinExchange::_getBtcValue(listStrInt_t::iterator const& it)
{
	for (mapStrInt_t::iterator it2 = _exchangeRate.begin(); it2 != _exchangeRate.end(); it2++)
	{
		if (it2->first >= it->first)
			return (it->second * it2->second);
	}
	return (2);
}