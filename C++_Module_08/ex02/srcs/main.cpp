/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:39:48 by galambey          #+#    #+#             */
/*   Updated: 2024/04/02 11:04:57 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <vector>         // std::vector
#include <deque>          // std::deque

int main (void) {

	std::string title = "\e[34m;";
	std::string reset = "\e[0m;";

	std::cout << title << " Tests constructors " << reset << std::endl;
	{
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
	std::cout << std::endl << title << " Tests subjects " << reset << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
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
	return (0);
}