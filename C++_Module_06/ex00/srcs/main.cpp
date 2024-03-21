/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:16 by galambey          #+#    #+#             */
/*   Updated: 2024/03/20 17:22:04 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/*
Pour realiser les tests pre ecrit, faire : make test
*/
int main (int ac, char **av) {
	
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
	}
	return (0);
}
