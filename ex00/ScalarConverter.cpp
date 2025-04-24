/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:59:13 by relamine          #+#    #+#             */
/*   Updated: 2025/04/24 19:33:39 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &b) : ConversionStrategy(b) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &b){(void)b; return (*this);}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& literal)
{
    ScalarConverter	a;
    LiteralType		type;
    char			c;
    int				i;
    float			f;
    double			d;


    type = a.detectType(literal);
	try
	{
		a.conversion(c, i, f, d, literal, type);	
    	a.display(c, i, f, d, literal);
	}
	catch (std::string& e)
	{
		a.display(0,0,0,0, e);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}
