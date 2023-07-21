/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:12:37 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 18:07:27 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SALARCONVERTER__
# define __SALARCONVERTER__

# include <string>
# include <exception>
# include <iostream>
# include <cstdlib>

enum e_type {
    INT,
    DOUBLE,
	FLOAT,
    CHAR,
	EXCEPTION,
	NO_LITERAL
};

class ScalarConverter
{
private:
	static e_type _detect_type(std::string & literal);
	static bool _is_exception;
	
	static bool	_no_printable_in_str(std::string const& literal);

	static bool _is_pseudo_literal(std::string literal);
	static bool _is_int(std::string const& literal);
	static bool _is_float(std::string const& literal);
	static bool _is_double(std::string const& literal);
	static bool _is_char(std::string const& literal);

	static void _printDouble(double nb);
	static void _printFloat(float nb);
	static void _printChar(char nb);
	

	static e_type	_convertPseudoLiteraux(std::string & literal);
	static void		_convert_from_int(std::string const& literal);
	static void		_convert_from_double(std::string const& literal);
	static void		_convert_from_float(std::string const& literal);
	static void		_convert_from_char(std::string const& literal);

	static void	_overflowVerify(std::string literal);


public:
	ScalarConverter(void){};
	ScalarConverter(ScalarConverter const& convert);
	~ScalarConverter(){};
	ScalarConverter&	operator=(ScalarConverter const& scalarConverter);
	static void	convert(char *literal);


	class NoValidInput : public std::exception
	{
		public:
		NoValidInput(std::string const& err)
		{
			_err = 	std::string("\033[1;31m")
					+ std::string("No Valid Input type error : ")
					+ err
					+ std::string("\033[0m");
		}
		virtual ~NoValidInput() throw(){};
		virtual const char* what() const throw()
		{
			return (_err.c_str());
		}
		private:
			std::string _err;
	};

	class OverflowInput : public std::exception
	{
		public:
		OverflowInput(std::string const& err)
		{
			_err = 	std::string("\033[1;31m")
					+ std::string("Overflow error: ")
					+ err
					+ std::string("\033[0m");
		}
		virtual ~OverflowInput() throw(){};
		virtual const char* what() const throw()
		{
			return (_err.c_str());
		}
		private:
			std::string _err;
	};

	class imppossibleError : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Une erreur completement innatendu, normalement impossible, s'est produite !");
		}
	};

	class NoLiteral : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("L'argument n'est pas un litéral !");
		}
	};
};


#endif