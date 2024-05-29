/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:44:28 by galambey          #+#    #+#             */
/*   Updated: 2024/05/29 11:23:34 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main() {
	std::string s = "42 02 05 89 10 30 1 45 5 6 8 64 98 58 12 10 4 65 98 32 67 45 25 7 95";
	// for (int i = 0; i < 10; i++)
		// std::cout << PmergeMe::jacobsthal_suit() << std::endl;
	PmergeMe a(s);
	// for (int i = 0; i < 10; i++)
	// 	std::cout << a.jacobsthal_suit() << std::endl;
	a.to_vector();
	
}