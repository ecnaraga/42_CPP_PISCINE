/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:49:54 by galambey          #+#    #+#             */
/*   Updated: 2024/03/29 15:36:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"

int randomNumber() {
	return (rand() % 2147483647);
}

int main()
{
	std::string title = "\e[34m";
	std::string err = "\e[31m";
	std::string reset = "\e[0m";
	
	std::cout << title << "Subject Main Test" << reset << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}
	
	std::cout << std::endl << title << "ShortestSpan on empty Span Test" << reset << std::endl;
	try {
		Span sp(0);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}

	std::cout << std::endl << title << "LongestSpan on empty Span Test" << reset << std::endl;
	try {
		Span sp(10);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}
	
	std::cout << std::endl << title << "addNumber on empty Span size of 0 Test" << reset << std::endl;
	try {
		Span sp(0);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}
	
	
	std::cout << std::endl << title << "Add Multiple Number Test" << reset << std::endl;
	try {
		Span sp(10);
		int myarray[10] = {12, 5, 6, 7, 8, 9, 10, 14, 98, 18};
		
		sp.addNumber(myarray, 10);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}

	std::cout << std::endl << title << "Add Multiple Number Test" << reset << std::endl;
	try {
		Span sp(10);
		int myarray[10] = {12, 47, 6, 36, 45, 58, 10, 14, 98, 18};
		std::vector<int> myvector;

		myvector.insert(myvector.begin(), myarray, myarray + 10);
		sp.addNumber(myvector);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}

	std::cout << std::endl << title << "Add 100000 Number using int array Test" << reset << std::endl;
	try {
		Span sp(100000);
		int myarray[100000];
		
		srand(time(NULL));
		std::generate_n(myarray, 100000, randomNumber);

		sp.addNumber(myarray, 100000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}

	std::cout << std::endl << title << "Add 10000 Number using vector Test" << reset << std::endl;
	try {
		Span sp(10000);
		std::vector<int> v(10000, 0);
		
		srand(time(NULL));
		std::generate_n(v.begin(), v.size(), randomNumber);

		sp.addNumber(v);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << err << e.what() << reset << std:: endl;
	}	
	
	return 0;
}
