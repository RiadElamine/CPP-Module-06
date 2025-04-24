/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:59:10 by relamine          #+#    #+#             */
/*   Updated: 2025/04/22 16:21:57 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ConversionStrategy.hpp"

class ScalarConverter : public ConversionStrategy
{
    ScalarConverter();
    ScalarConverter(const ScalarConverter &b);
    ScalarConverter &operator=(const ScalarConverter &b);
    ~ScalarConverter();

    public:
        static void convert(const std::string& literal);
};
