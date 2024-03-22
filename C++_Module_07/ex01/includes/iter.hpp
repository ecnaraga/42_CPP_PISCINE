/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:31:43 by garance           #+#    #+#             */
/*   Updated: 2024/03/22 13:34:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstring>

template <class To, class From> // Pour pouvoir instancier la fonction dans le code, il faut definir un template pour le type retour egalement
To print(From f) {
	std::cout << f << " ";
}

template <class T, class To, class From>
void iter(T & array, int len, To (*f)(From)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

#endif