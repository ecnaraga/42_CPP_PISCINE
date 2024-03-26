/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:21:01 by galambey          #+#    #+#             */
/*   Updated: 2024/03/26 15:20:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main (void) {

	std::string title = "\e[34m";	
	std::string reset = "\e[0m";
	
	{
		std::cout << title << "test Iter avec une string" << reset << std::endl;
		std::string s = "Hello";
		iter(s, s.length(), test<char>);
		// void (*f)(char &) = test; // Autre methode
		// iter(s, s.length(), f);
	}
	{
		std::cout << std::endl << title << "test Iter avec une string" << reset << std::endl;
		std::string s[] = {"Hello", "World"};
		iter(s, 2, test<std::string>);
		// void (*f)(std::string &) = test; // Autre methode
		// iter(s, 2, f);
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de char" << reset << std::endl;
		char s[6] = {'W', 'o', 'r', 'l', 'd'};
		iter(s, strlen(s), test<char>);
		// void (*f)(char &) = test; // Autre methode
		// iter(s, strlen(s), f);
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de char en castant des char const" << reset << std::endl;
		char s[6] = {'W', 'o', 'r', 'l', 'd'};
		iter(s, strlen(s), test< char const >);
		// void (*f)(char const &) = test; // Autre methode
		// iter(s, strlen(s), f);
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de int" << reset << std::endl;
		int array[10] = {1, 25, 13, 6, 15, 8, 7, 9, 89, 14};
		iter(array, 10, test<int>);
		// void (*f)(int &) = test; // Autre methode
		// iter(array, 10, f);
	}
	{
		std::cout << std::endl << std::endl << title << "test Iter avec un array de int  en castant des int const" << reset << std::endl;
		int const array[10] = {1, 25, 13, 6, 15, 8, 7, 9, 89, 14};
		iter(array, 10, test<int const>);
		// void (*f)(int const &) = test;  // Autre methode
		// iter(array, 10, f);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
