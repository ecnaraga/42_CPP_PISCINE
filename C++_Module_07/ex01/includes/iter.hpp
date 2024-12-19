/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:31:43 by garance           #+#    #+#             */
/*   Updated: 2024/03/26 15:16:39 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstring>

template <typename U>
void test(U & f) {
	std::cout << f << std::endl;
}

template <typename T , typename U>
void iter(T & array, int len, void (*f)(U &)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

/*
Autre methode : le type U represente la fonction directement
*/
// template <typename T , typename U>
// void iter(T & array, int len, U * f) {
// 	for (int i = 0; i < len; i++)
// 		f(array[i]);
// }

/*
=> marche pour quasiment tous les tableaux, mais pas de string a char car pas le meme type
	d 'ou l interet d utiliser deux typenames differents
// template <class T >
// void iter(T *array, int len, void(*f)(T const &elem)) {
// 	for (int i = 0; i < len; i++) {
// 		// T &elem = array[i];
// 		// f(elem);
// 		f(array[i]);
// 	}
// }

// template <class T>
// void iter(T * array, int len, void (*f)(T &)) {
// 	for (int i = 0; i < len; i++)
// 		f(array[i]);
// }
*/


#endif