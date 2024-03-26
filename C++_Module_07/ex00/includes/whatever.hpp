/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:37:10 by galambey          #+#    #+#             */
/*   Updated: 2024/03/26 16:27:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <class T>
T const & max(T const & a, T const & b) {
    return (a >= b ? a : b);
}

template <typename T>
T const & min(T const & a, T const & b) {
    return (a <= b ? a : b);
}

template <typename T>
void swap(T & a, T & b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

#endif