/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:49:37 by galambey          #+#    #+#             */
/*   Updated: 2024/03/21 15:49:25 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void) {
	
	int i = rand() % 3;
	switch (i) {
		case 0 :
			// std::cout << "return type A" << std::endl;
			return (new A);
		case 1 :
			// std::cout << "return type B" << std::endl;
			return (new B);
		case 2 :
			// std::cout << "return type C" << std::endl;
			return (new C);
	}
	return (NULL);
}

void identify(Base * p) {
	A* typeA = dynamic_cast<A*>(p);
	if (typeA) {
		std::cout << "Object is type A" << std::endl;
		return ;
	}
	B* typeB = dynamic_cast<B*>(p);
	if (typeB) {
		std::cout << "Object is type B" << std::endl;
		return ;
	}
	C* typeC = dynamic_cast<C*>(p);
	if (typeC) {
		std::cout << "Object is type C" << std::endl;
		return ;
	}
}

void identify(Base & p) {
	try {
		A typeA = dynamic_cast<A&>(p);
		std::cout << "Object is type A" << std::endl;
		return ;
	}
	catch (std::exception &bad_cast) {}
	try {
		B typeB = dynamic_cast<B&>(p);
		std::cout << "Object is type B" << std::endl;
		return ;
	}
	catch (std::exception &bad_cast) {}
	try {
		C typeC = dynamic_cast<C&>(p);
		std::cout << "Object is type C" << std::endl;
		return ;
	}
	catch (std::exception &bad_cast) {}
}

int main(void) {
	srand (time(NULL)); // reinitialise le random seed 
	for (int i = 0; i < 10; i++) {
		std::cout << std::endl;
		Base * base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return (0);
}
