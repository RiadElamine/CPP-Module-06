/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionStrategy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:20:41 by relamine          #+#    #+#             */
/*   Updated: 2025/04/24 20:37:23 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ConversionStrategy.hpp"

ConversionStrategy::ConversionStrategy(){}

ConversionStrategy::ConversionStrategy(const ConversionStrategy& c){(void)c;}

ConversionStrategy& ConversionStrategy::operator=(const ConversionStrategy& c){(void)c; return (*this);}

ConversionStrategy::~ConversionStrategy(){}

bool ConversionStrategy::isValidCharLiteral(const std::string& str)
{
    return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

bool ConversionStrategy::isValidIntLiteral(const std::string& str)
{
    size_t  i;
    size_t  lenght;

    i = 0;
    lenght = str.length();
    if (i < lenght && isspace(str[i]))
        return (false);
    if (i < lenght && (str[i] == '-' || str[i] == '+'))
        i++;
    while (i < lenght && std::isdigit(str[i]))
        i++;
    return (lenght == i);  
}

bool ConversionStrategy::isValidFloatLiteral(const std::string& str)
{
    size_t  i;
    size_t  length;
    int     count_dot;
    int     count_f;

    if (str == "nanf" || str == "+inff" || str == "-inff")
        return (true);
    i = 0;
    count_dot = 0;
    count_f = 0;
    length = str.length();
    if (i < length && isspace(str[i]))
        return (false);
    if (i < length && (str[i] == '-' || str[i] == '+'))
        i++;
    while (i < length && (std::isdigit(str[i]) || str[i] == '.' || tolower(str[i]) == 'f'))
    {
        if (str[i] == '.')
            count_dot++;
        if (tolower(str[i]) == 'f')
            count_f++;
        i++;
    }
    return (count_dot == 1 && count_f == 1 && i == length);  
}

bool ConversionStrategy::isValidDoubleLiteral(const std::string& str)
{
    size_t  i;
    size_t  length;
    int     count_dot;
    int     count_d;

    if (str == "nan" || str == "+inf" || str == "-inf") 
        return (true);
    i = 0;
    count_dot = 0;
    count_d = 0;
    length = str.length();
    if (i < length && (isspace(str[i])))
        return (false);
    if (i < length && (str[i] == '-' || str[i] == '+'))
        i++;
    while (i < length && (std::isdigit(str[i]) || str[i] == '.' || tolower(str[i]) == 'd'))
    {
        if (str[i] == '.')
            count_dot++;
        if (str[i] == 'd')
            count_d++;
        i++;
    }
    return (length == i && count_dot == 1 && count_d <= 1);  
}

LiteralType ConversionStrategy::detectType(const std::string& input)
{
    if (isValidCharLiteral(input))
        return (_CHAR);
    if (isValidIntLiteral(input))
        return (_INT);
    if (isValidDoubleLiteral(input))
        return (_DOUBLE);
    if (isValidFloatLiteral(input))
        return (_FLOAT);
    return (_UNKNOWN);
}

void        ConversionStrategy::conversion(char &c, int &i, float &f, double &d, const std::string &literal, LiteralType	type)
{
    switch (type)
    {
        case _CHAR:
            c = literal[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        case _INT: {
                std::stringstream s(literal);
                if (!(s >> i))
                {
                    throw std::string("impossible");
                }
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;
            }
        case _FLOAT:
            f = std::atof(literal.c_str());
            i = static_cast<int>(f);
            c = static_cast<char>(i);
            d = static_cast<double>(f);
            break;
        case _DOUBLE:
            d = std::strtod(literal.c_str(), NULL);
            i = static_cast<int>(d);
            c = static_cast<char>(i);
            f = static_cast<float>(d);
            break;
        default:
            throw std::invalid_argument("Unknown literal type");
    }
}

bool        ConversionStrategy::isPseudoLiteral(const std::string& input, float &f, double &d)
{
    float limits_f = std::numeric_limits<float>::infinity();
    float limits_d = std::numeric_limits<double>::infinity();
    return (f == limits_f || f == -limits_f || d ==  limits_d || d == -limits_d ||
            input == "nan" || input == "+inf" || input == "-inf" ||
            input == "nanf" || input == "+inff" || input == "-inff" || input == "impossible");
}

void        ConversionStrategy::display(char c, int i, float f, double d, std::string input)
{
    if (isPseudoLiteral(input, f, d)) 
    {
        std::cout << "char: "<< "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        if (input == "nanf" || input == "+inff" || input == "-inff")
        {
            std::cout << "float: " << input << std::endl;
            input.erase(input.length() - 1);
            std::cout << "double: " << input << std::endl;
        }
        else if (input == "nan" || input == "+inf" || input == "-inf")
        {
            input.push_back('f');
            std::cout << "float: " << input << std::endl;
            input.erase(input.length() - 1);
            std::cout << "double: " << input << std::endl;
        }
        else if (input == "impossible")
        {
            std::cout << "float: "<< "impossible" << std::endl;
            std::cout << "double: " << "impossible" << std::endl;
        }
        else
        {
            std::cout << "float: " << f << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        return ;
    }

    std::cout << "char: "; 
    if (c < 32  || c == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: ";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else 
        std::cout << i << std::endl;

    std::cout << "float: ";
    std::cout << f;
    if ((f - i) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: ";
    std::cout << d;
    if ((d - i) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

