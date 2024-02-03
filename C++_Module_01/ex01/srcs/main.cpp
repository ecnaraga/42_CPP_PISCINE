/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:15:42 by galambey          #+#    #+#             */
/*   Updated: 2024/02/03 12:16:34 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"
# include <sstream>
#include <fstream>

int	ft_stoi(std::string s, int *err) {
	
	int result = 0;
	int begin = 0;
	int count = 0;

	if (!s[0])
		return (*err = 1, result);
	for (int i = 0; s[i]; i++) {
		if (!isdigit(s[i]))
		{
			*err = 1;
			return (result);
		}
		if (s[i] != '0')
			begin = 1;
		if (begin != 1)
			count++;
	}
	if (count > 10)
		return (*err = 1, result);
	std::istringstream(s) >> result;
	return (result);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int err = 0;
		int N = ft_stoi(av[1], &err);
		if (err == 1)
		{
			std::cout << "wrong parameter" << std::endl;
			return (1);
		}
		
		Zombie* A = NULL;
		std::string s = av[2];
		A = A->Zombie::zombieHorde(N, s);
		for(int i = 0; i < N; i++) {
			A->announce();
			A++;
			std::cout << std::endl;	
		}
		delete A;
	}
	return (0);
}
