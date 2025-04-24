/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionStrategy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:21:07 by relamine          #+#    #+#             */
/*   Updated: 2025/04/24 17:46:57 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>

enum LiteralType
{
    _CHAR,
    _INT,
    _FLOAT,
    _DOUBLE,
    _UNKNOWN
};

class ConversionStrategy
{
        bool isValidCharLiteral(const std::string& str);  
        bool isValidIntLiteral(const std::string& str);   
        bool isValidFloatLiteral(const std::string& str);
        bool isValidDoubleLiteral(const std::string& str);
        bool isPseudoLiteral(const std::string& input, float &f, double &d);

    public:
        ConversionStrategy();
        ConversionStrategy(const ConversionStrategy &c);
        ConversionStrategy &operator=(const ConversionStrategy &c);
        ~ConversionStrategy();

        LiteralType detectType(const std::string& input);
        void        conversion(char &c, int &i, float &f, double &d, const std::string &literal, LiteralType type);
        void        display(char c, int i, float f, double d, std::string input);
};
