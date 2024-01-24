/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:44:09 by galambey          #+#    #+#             */
/*   Updated: 2024/01/24 14:48:44 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	i = 1;
	int	j;
	int	len;
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < ac; i++)
		{
			std::string	strupp = av[i];
			len = strupp.length();
			for(j = 0; j < len; j++)
				strupp[j] = toupper(strupp[j]);
			if (i < ac - 1)
				std::cout << strupp;
			else
				std::cout << strupp << std::endl;
		}
	}
	return (0);
}
