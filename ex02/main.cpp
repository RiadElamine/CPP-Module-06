/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:57:24 by relamine          #+#    #+#             */
/*   Updated: 2025/04/25 22:55:25 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyRealType.hpp"

int main(void)
{
    Base* shared_ptr = generate();

    identify(*shared_ptr);
    identify(shared_ptr);

    delete shared_ptr;

    return (0);
}