/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:55:11 by relamine          #+#    #+#             */
/*   Updated: 2025/04/24 23:47:55 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d = {1337};
    uintptr_t raw = Serializer::serialize(&d);

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &d)
    {
        std::cout << "Success! Pointer recovered correctly.\n";
        std::cout << "recovered ptr: " << ptr->x << ", origine ptr: " << d.x << '\n';
    }
    else
    {
        std::cout << "Error: Pointers do not match!\n";
    }
}