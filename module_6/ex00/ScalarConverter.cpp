/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:27:27 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 18:30:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <limits>

bool ScalarConverter::_is_exception = false;


void	ScalarConverter::convert(char *literal)
{
	std::string str(literal); // Converti le char * en string
	//std::fixed;
	std::cout.precision(10);
	std::string literalCpy = literal;
	try {
		
		//std::cout << "Je pense que c'est un type..." << _detect_type(literal) << std::endl;

		switch (_detect_type(literalCpy))
		{
			case INT : _convert_from_int(literalCpy) ; break;
			case DOUBLE : _convert_from_double(literalCpy) ; break;
			case FLOAT : _convert_from_float(literalCpy) ; break;
			case CHAR : _convert_from_char(literalCpy) ; break;
			case NO_LITERAL : throw  NoLiteral(); break;
			default : break;
		}

	}
	catch(std::exception const& e)
	{
		throw;
	}
}

e_type	ScalarConverter::_convertPseudoLiteraux(std::string & literal)
{
	ScalarConverter::_is_exception = true;
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return static_cast<e_type>(FLOAT);
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return static_cast<e_type>(DOUBLE);
	return static_cast<e_type>(CHAR);
}

bool ScalarConverter::_is_pseudo_literal(std::string literal)
{
	if (	literal == "+inff"
		|| 	literal == "-inff"
		|| 	literal == "nanf"
		|| 	literal == "+inf"
		|| 	literal == "-inf"
		|| 	literal == "nan"
		)
		return (true);
	return (false);
}


e_type		ScalarConverter::_detect_type(std::string & literal)
{
	if (_no_printable_in_str(literal))
		throw NoValidInput("No printable character found");
	if (_is_pseudo_literal(literal))
		return _convertPseudoLiteraux(literal);
	if (_is_int(literal))
		return static_cast<e_type>(INT);
	else if (_is_double(literal))
		return static_cast<e_type>(DOUBLE);
	else if (_is_float(literal))
		return static_cast<e_type>(FLOAT);
	else if (_is_char(literal))
		return static_cast<e_type>(CHAR);
	else
		return static_cast<e_type>(NO_LITERAL);
}

bool	ScalarConverter::_no_printable_in_str(std::string const& literal)
{
    for (size_t i = 0; i < literal.length(); ++i) {
        if (!std::isprint(literal[i])) {
            return true;
        }
    }
    return false;
}

/*Si tout les caracteres sont compris entre '0' et '9', c'est un nombre.
Si y'a un + ou un - au debut on accepte, on est pas des monstres*/
bool ScalarConverter::_is_int(std::string const& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	}
	return (true);
}

/*
	Pour un doucle, on parcours chaque caractere.
	Si c'est pas un 0, un 9, ou un ., on return false
	On compte au passage le nombre de -
	Le nombre de . doit être 1 pour renvoyer true
	Puis on pardonne le + ou - du debut
*/
bool ScalarConverter::_is_double(std::string const& literal)
{
	int	nb_dot = 0;
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] < '0' || literal[i] > '9')
		{
			if (literal[i] != '.')
				return ((false));
			nb_dot++;
		}
	}
	if (nb_dot != 1)
		return (false);
	return (true);
}

/*
	Pour un float, il faut bien que le dernier caractere soit un f.
	Si c'est le cas, alors on regarde si la partie avant le f est un double
*/
bool ScalarConverter::_is_float(std::string const& literal)
{
	if (literal[literal.length() - 1] != 'f')
		return (false);
	std::string numberWithoutF = literal.substr(0, literal.length() - 1);
	if (!_is_double(numberWithoutF) && !_is_int(numberWithoutF))
		return (false);
	return (true);
}

bool ScalarConverter::_is_char(std::string const& literal)
{
	if (literal.length() == 1)
		return (true);
	return (false);
}

void	ScalarConverter::_convert_from_int(std::string const& literal)
{
	int		int_v = std::atoi(literal.c_str());
	double	double_v = static_cast<double>(int_v);
	float	float_v = static_cast<float>(int_v);
	char	&char_v = reinterpret_cast<char &>(int_v);
	
	_overflowVerify(literal);
	_printChar(char_v);
	std::cout << "int: " << int_v << std::endl;
	_printFloat(float_v);
	_printDouble(double_v);
}

void	ScalarConverter::_convert_from_double(std::string const& literal)
{
	char 	*end;
	double	double_v = std::strtod(literal.c_str(), &end);
	// Si la conversion a echoue, end pointe sur literal.c_str()
	if (end == literal.c_str())
		throw ScalarConverter::imppossibleError();

	int		int_v = static_cast<int>(double_v);
	float	float_v = static_cast<float>(double_v);
	char	char_v = static_cast<char>(double_v);
	
	if (ScalarConverter::_is_exception)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (float_v - int_v == 0)
			_printChar(char_v);
		else
			std::cout << "char: impossible" << std::endl;

		std::cout << "int: " << int_v << std::endl;
	}


	_printFloat(float_v);
	_printDouble(double_v);
}

void	ScalarConverter::_convert_from_float(std::string const& literal)
{
	char 	*end;

	std::string literalCpy = literal;
	literalCpy.erase(literalCpy.length() - 1, 1);

	float float_v = std::strtof(literalCpy.c_str(), &end);
	// Si la conversion a echoue, end pointe sur literal.c_str()
	if (end == literal.c_str())
		return ;

	int		int_v 		= static_cast<int>(float_v);
	double	double_v 	= static_cast<float>(float_v);
	char	char_v		= static_cast<char>(float_v);
	
	if (float_v - int_v == 0)
		_printChar(char_v);
	else
		std::cout << "char: impossible" << std::endl;
	if (ScalarConverter::_is_exception)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int_v << std::endl;

	_printFloat(float_v);
	_printDouble(double_v);
}

void	ScalarConverter::_convert_from_char(std::string const& literal)
{
	char	char_v = literal.at(0);
	int		int_v 		= static_cast<int>(char_v);
	double	double_v 	= static_cast<float>(char_v);
	char	float_v		= static_cast<char>(char_v);
	_printChar(char_v);
	std::cout << "int: " << int_v << std::endl;
	_printFloat(float_v);
	_printDouble(double_v);
}

void ScalarConverter::_printDouble(double nb)
{
	std::cout << "double: ";
	
	std::cout << nb;
	if (nb - static_cast<int>(nb) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::_printFloat(float nb)
{
	std::cout << "float: ";
	std::cout << nb;
	if (nb - static_cast<int>(nb) == 0)
		std::cout << ".0";
	std::cout << "f";
	std::cout << std::endl;
}

void ScalarConverter::_printChar(char char_v)
{
	if (char_v > 31 && char_v < 127)
	{
		std::cout << "char: '" << char_v << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

/*
	Vérifie si il y a overflow
	On verifie sur une chaine dont on sait deja que c'est un nombre
*/
void	ScalarConverter::_overflowVerify(std::string str_nb)
{
	std::ostringstream intMaxOs;
    intMaxOs << std::numeric_limits<int>::max();
	std::string intMaxStr = static_cast<std::string>(intMaxOs.str());


	std::ostringstream intMinOs;
    intMinOs << std::numeric_limits<int>::min();
	std::string intMinStr = static_cast<std::string>(intMinOs.str());

	if (str_nb[0] == '-')
	{
		if (str_nb.length() > intMinStr.length())
			throw OverflowInput("Number inferior than int min");
		if ((str_nb.length() == intMinStr.length()) && str_nb > intMinStr)
			throw OverflowInput("Number inferior than int mint");
	}
	else
	{
		if (str_nb.length() > intMaxStr.length())
			throw OverflowInput("Number superior than int max");

		if ((str_nb.length() == intMaxStr.length()) && str_nb > intMaxStr)
			throw OverflowInput("Number superior than int max");
	}
}


ScalarConverter::ScalarConverter(ScalarConverter const& convert){
	static_cast<ScalarConverter>(convert);

};


ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& scalarConverter){
	static_cast<ScalarConverter>(scalarConverter);
	return (*this);
};
