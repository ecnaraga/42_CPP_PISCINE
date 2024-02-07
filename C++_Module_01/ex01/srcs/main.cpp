/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:15:42 by galambey          #+#    #+#             */
/*   Updated: 2024/02/07 10:30:29 by galambey         ###   ########.fr       */
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
	if (ac != 3) {
		std::cout << "Wrong parameter. Please try again with :" << std::endl;
		std::cout << "  > First parameter : number" << std::endl;
		std::cout << "  > Second parameter : string" << std::endl;
		return (1);
	}
	int err = 0;
	int N = ft_stoi(av[1], &err);
	if (err == 1)
	{
		std::cout << "Wrong parameter. Please try again with :" << std::endl;
		std::cout << "  > First parameter : number" << std::endl;
		std::cout << "  > Second parameter : string" << std::endl;
		return (1);
	}
	
	Zombie* A = NULL;
	std::string s = av[2];
	A = A->Zombie::zombieHorde(N, s);
	
	/* Incrementation de l'index */
	for(int i = 0; i < N; i++) {
		A[i].announce();
		std::cout << std::endl;	
	}
	
	/* Incrementation du pointeur */
	// Zombie* tmp = A;
	// for(int i = 0; i < N; i++) {
	// 	A->announce();
	// 	A++;
	// 	std::cout << std::endl;	
	// }
	// A = tmp;
	
	delete[] A;
	return (0);
}
