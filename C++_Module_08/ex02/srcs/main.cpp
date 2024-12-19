/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:39:48 by galambey          #+#    #+#             */
/*   Updated: 2024/05/30 13:47:11 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>         // std::list
#include <vector>         // std::vector
#include <deque>          // std::deque

int main (void) {

	std::string title = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << title << "Tests constructors" << reset << std::endl;
	try {
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		MutantStack<int> first;                    // empty stack
		MutantStack<int> second (mydeque);         // stack initialized to copy of deque

		MutantStack<int,std::vector<int> > third;  // empty stack using vector
		MutantStack<int, std::vector<int> > fourth (myvector);
		MutantStack<int, std::vector<int> > fifth (fourth); // cpy constructor on stack using vector

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
		std::cout << "size of fifth: " << fifth.size() << '\n';
	}
	catch (std::bad_alloc const & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << title << "Tests subjects with MutantStack" << reset << std::endl;
	try {
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
	}
	catch (std::bad_alloc const & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << title << "Tests subjects with list => to compare" << reset << std::endl;
	try {
		std::list<int> list_c;
		
		list_c.push_back(5);
		list_c.push_back(17);
		
		std::cout << list_c.back() << std::endl;
		
		list_c.pop_back();

		std::cout << list_c.size() << std::endl;
		
		list_c.push_back(3);
		list_c.push_back(5);
		list_c.push_back(737);
		list_c.push_back(0);
		
		std::list<int>::iterator it = list_c.begin();
		std::list<int>::iterator ite = list_c.end();
		
		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::bad_alloc const & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << title << "Tests subjects with MutantStack with reverse iterator" << reset << std::endl;
	try {
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		
		++rit;
		--rit;

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
		
		std::stack<int> s(mstack);
	}
	catch (std::bad_alloc const & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << title << "Tests subjects with list with reverse iterator => to compare" << reset << std::endl;
	try {
		std::list<int> list_c;
		
		list_c.push_back(5);
		list_c.push_back(17);
		
		std::cout << list_c.back() << std::endl;
		
		list_c.pop_back();

		std::cout << list_c.size() << std::endl;
		
		list_c.push_back(3);
		list_c.push_back(5);
		list_c.push_back(737);
		list_c.push_back(0);
		
		std::list<int>::reverse_iterator rit = list_c.rbegin();
		std::list<int>::reverse_iterator rite = list_c.rend();
		
		++rit;
		--rit;

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	catch (std::bad_alloc const & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << title << "More tests with MutantStack" << reset << std::endl;
	try {
		std::string strs[] = {"Hello,", "how", "are", "you?"};
		std::vector<std::string> v(strs, strs + sizeof(strs) / sizeof(std::string));
		MutantStack<std::string, std::vector<std::string > > mstack(v);
		MutantStack<std::string, std::vector<std::string > > mstack_cpy;

		mstack_cpy = mstack;

		mstack_cpy.push("Good,");
		mstack_cpy.push("thanks");

		std::cout << "Size of mstack = " << mstack.size() << std::endl;
		std::cout << "Size of mstack_cpy = " << mstack_cpy.size() << std::endl;
		
		MutantStack<std::string, std::vector<std::string> >::iterator it;
		MutantStack<std::string, std::vector<std::string> >::iterator ite = mstack_cpy.end();

		for (it = mstack_cpy.begin(); it != ite; it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		mstack_cpy.pop();
		mstack_cpy.push("thank you :D");
		
		MutantStack<std::string, std::vector<std::string> >::reverse_iterator rit;
		MutantStack<std::string, std::vector<std::string> >::reverse_iterator rite = mstack_cpy.rend();

		for (rit = mstack_cpy.rbegin(); rit != rite; rit++)
			std::cout << *rit << std::endl;

	}
	catch (std::bad_alloc const & e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
