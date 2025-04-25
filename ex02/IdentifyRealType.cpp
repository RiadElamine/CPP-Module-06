/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyRealType.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:56:58 by relamine          #+#    #+#             */
/*   Updated: 2025/04/25 22:55:15 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyRealType.hpp"

Base::~Base(){}

Base	*generate(void)
{
    srand(time(0));
    switch (rand() % 3)
    {
        case 1:
            return (new A());
        case 2:
            return (new B());
        default :
            return (new C());
    }
}

void	identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown type" << std::endl;
}

void	identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "unknown type" << std::endl;
            }
            
        }
        
    }
    
}
