/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:57:08 by galambey          #+#    #+#             */
/*   Updated: 2024/03/26 17:32:28 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
int easyfind(T & container, int const & tofind)
{
	T::iterator it;
	
	it = std::find(container.begin(), container.end(), tofind);
	if (it != container.end())
		return *it;
}

#endif