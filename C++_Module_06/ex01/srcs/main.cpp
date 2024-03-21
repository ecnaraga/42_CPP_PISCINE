/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:59:11 by garance           #+#    #+#             */
/*   Updated: 2024/03/21 15:54:35 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"
#include <iostream>

int main(void) {

    std::string title = "\e[34m";    
    std::string reset = "\e[0m";
        
    //Avec un pointeur valide
    Data p;
    uintptr_t ptr_dec = Serializer::serialize(&p);
    Data *ptr = Serializer::deserialize(ptr_dec);

    std::cout << std::endl << title << "Avec un pointeur non NULL" << reset << std::endl;
    std::cout << "Adresse de p : " << &p << std::endl;
    std::cout << "p.age = " << p.age << std::endl;
    std::cout << "Adresse de p convertie en uintprt_t : " << ptr_dec << std::endl;
    std::cout << "uintptr convertie en Data * : " << ptr << std::endl;
    std::cout << "ptr.age = " << ptr->age << std::endl;

    //Avec NULL
    std::cout << std::endl << title << "Avec un pointeur NULL" << reset << std::endl;
    ptr_dec = Serializer::serialize(NULL);
    ptr = Serializer::deserialize(ptr_dec);
    std::cout << "Pointeur NULL converti en uintprt_t : " << ptr_dec << std::endl;
    std::cout << "uintptr convertie en Data * : " << ptr << std::endl;
    
    return (0);
}