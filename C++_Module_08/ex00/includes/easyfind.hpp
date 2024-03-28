/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:57:08 by galambey          #+#    #+#             */
/*   Updated: 2024/03/28 11:38:40 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class AbsentValueException : public std::exception {
	const char * what() const throw();
};

template <typename T>
int easyfind(T & container, int const & tofind)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), tofind);
	if (it != container.end())
		return *it;
	throw(AbsentValueException());
}

#endif
