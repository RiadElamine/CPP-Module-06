/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyRealType.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:57:14 by relamine          #+#    #+#             */
/*   Updated: 2025/04/25 22:51:34 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>

class Base
{
    public:
		virtual	~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);
