/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:21:01 by galambey          #+#    #+#             */
/*   Updated: 2024/03/22 13:35:02 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main (void) {

	std::string title = "\e[34m";	
	std::string reset = "\e[0m";
	
	std::cout << title << "test Iter avec une string" << reset << std::endl;
	std::string s = "Hello";
	void (*f)(char) = print; // instancie print
	::iter(s, s.length(), f);
	
	std::cout << std::endl << std::endl << title << "test Iter avec un array de char" << reset << std::endl;
	char str[6];
		str[0] = 'W';
		str[1] = 'o';
		str[2] = 'r';
		str[3] = 'l';
		str[4] = 'd';
		str[5] = 0;
		::iter(str, strlen(str), print<void, char>); // appelle print
		
	std::cout << std::endl << std::endl << title << "test Iter avec un array de int" << reset << std::endl;
	int a[10] = {1, 25, 13, 6, 15, 8, 7, 9, 89, 14};
	void (*f1)(int) = print;
	::iter(a, 10, f1);
	std::cout << std::endl;
	
	return (0);
}
