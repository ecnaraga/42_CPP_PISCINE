/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:49:54 by galambey          #+#    #+#             */
/*   Updated: 2024/03/28 18:27:55 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

// int main()
// {
// 	std::vector<int> myvector;
// 	std::vector<int>::iterator it;

// 	it = myvector.begin();
// 	it = myvector.insert(it, 200);
// 	it = myvector.end();
// 	it = myvector.insert(it, 300);
// 	it = myvector.end();
// 	it = myvector.insert(it, 400);
// 	it = myvector.begin();

// 	for (it = myvector.begin(); it < myvector.end(); it++)
// 		std::cout << *it << std::endl;
	
// }