/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:37:10 by galambey          #+#    #+#             */
/*   Updated: 2024/03/22 11:15:41 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class myType>
myType max(myType a, myType b) {
    return (a >= b ? a : b);
}

template <class myType>
myType min(myType a, myType b) {
    return (a <= b ? a : b);
}

template <class myType>
void swap(myType & a, myType  & b) {
    myType tmp;

    tmp = a;
    a = b;
    b = tmp;
}

#endif