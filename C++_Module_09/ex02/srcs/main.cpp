/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:44:28 by galambey          #+#    #+#             */
/*   Updated: 2024/06/05 16:40:01 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// ATTENTION PAS DE NB NEGATIF => A INCLURE
// ATTENTION A PARSER ARG ET VERIF SI NB ET PAS D OVERFLOW D ATOI
int	main(int ac, char** av) {
	if (ac < 2)
	{
		std::cout << "Error : Arguments missing" << std::endl;
		return (1);
	}
	try {
		PmergeMe a(ac, av);  // check si atoi overflow  dans constructeur ?
		a.to_vector();
	}
	catch (std::bad_alloc & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		PmergeMe a(ac, av);  // check si atoi overflow  dans constructeur ?
		a.to_deque();
	}
	catch (std::bad_alloc & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}

// #include <iostream>     // std::cout
// #include <algorithm>    // std::merge, std::sort
// #include <vector>       // std::vector

// int main () {
//   int first[] = {5,10,15,20,25};
//   int second[] = {50,40,30,20,10};
//   int three[10];
// //   std::vector<int> v(10);

//   std::sort (first,first+5);
//   std::sort (second,second+5);
//   std::merge (first,first+5,second,second+5,three);

//   std::cout << "The resulting vector contains:";
//   for (int i = 0; i < 10; i++)
//     std::cout << ' ' << three[i];
//   std::cout << '\n';

//   return 0;
// }
