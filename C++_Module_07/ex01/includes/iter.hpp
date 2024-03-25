/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:31:43 by garance           #+#    #+#             */
/*   Updated: 2024/03/25 18:19:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstring>

template <typename From> // Pour pouvoir instancier la fonction dans le code, il faut definir un template pour le type retour egalement
void test(From & f) {
	std::cout << f << " ";
}

// template <class T>
// void iter(T & array, int len, void (*f)(T)) {
// 	for (int i = 0; i < len; i++)
// 		f(array[i]);
// }


// template <class T, class From>
template <typename T, typename From>
void iter(T & array, int len, void (*f)(From)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

#endif