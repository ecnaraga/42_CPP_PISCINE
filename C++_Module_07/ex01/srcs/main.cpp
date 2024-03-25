/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:21:01 by galambey          #+#    #+#             */
/*   Updated: 2024/03/25 18:21:38 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main (void) {

	std::string title = "\e[34m";	
	std::string reset = "\e[0m";
	
	{
		std::cout << title << "test Iter avec une string" << reset << std::endl;
		std::string s = "Hello";
		void (*f)(char const &) = test; // instancie test
		iter(s, s.length(), f);
		// iter<std::string, char const &>(s, s.length(), f); on peut appeler la fonction iter avec ou sans la precision des elements
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de char" << reset << std::endl;
		char s[6] = {'W', 'o', 'r', 'l', 'd'};
		iter(s, strlen(s), test<char>); // appelle test
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de char en castant des char const" << reset << std::endl;
		char s[6] = {'W', 'o', 'r', 'l', 'd'};
		iter(s, strlen(s), test<char const>); // appelle test
		// iter(s, strlen(s), test); // appelle test
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de int" << reset << std::endl;
		int array[10] = {1, 25, 13, 6, 15, 8, 7, 9, 89, 14};
		void (*f)(int &) = test;
		iter(array, 10, f);
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de int  en castant des int const" << reset << std::endl;
		int const array[10] = {1, 25, 13, 6, 15, 8, 7, 9, 89, 14};
		void (*f)(int const &) = test;
		iter(array, 10, f);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return (0);
}

