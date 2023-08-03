/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:12:51 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/03 15:12:40 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE__
#define __BITCOIN_EXCHANGE__

#include <map>
#include <list>
#include <string>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

typedef	std::pair<std::string, float> pairMap_t;
typedef std::map<std::string, float> mapStrInt_t;
typedef std::list< pairMap_t > listStrInt_t;


class BitcoinExchange
{
private:
	mapStrInt_t 	_exchangeRate;
	listStrInt_t 	_inputData;
	BitcoinExchange(void);

	void	_checkValidDate(std::string const& date, int i);
	void	_checkValidNumber(std::string const& number, int i);
	void	_checkRangeNumber(float const& number);
	float	_getBtcValue(listStrInt_t::iterator const& it);

public:
	BitcoinExchange(const char * dataFileName);
	BitcoinExchange(BitcoinExchange const& otherBE);
	~BitcoinExchange();
	BitcoinExchange&	operator=(BitcoinExchange const& otherBE);

	void	setInputData(const char * inputDataName);
	void		calculateInput();

	class HandleDataError : public std::exception
	{
	public:
		std::string error;
		HandleDataError(std::string const& errorPhrase,int const& lign)
		{
			if (lign != -1)
			{
				std::ostringstream oss;
				oss << lign;
				std::string lineNb = oss.str();
				error = errorPhrase + " - Line : " + lineNb;
			}
			else
				error = errorPhrase;

		}
		~HandleDataError() throw(){}
		const char* what() const throw()
		{
			return (error.c_str());
		}
	};

	class InvalidDataFile : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "InvalidDataFile: The file with the datas was not properly open";
		}
	};

	class InvalidInputFile : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "InvalidInputFile: The file with the inputs was not properly open. Verfiy it does exist and the access right";
		}
	};
};

#endif