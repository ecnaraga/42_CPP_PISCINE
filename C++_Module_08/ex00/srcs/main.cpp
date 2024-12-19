#include <iostream>
#include <vector>       // std::vector
#include <deque>        // std::deque
#include <list>         // std::list
#include <stack>        // std::stack
#include <cstdlib>
#include "../includes/easyfind.hpp"

const char * AbsentValueException::what() const throw() {
	return ("Value is absent in that container");
}

int main () {
	
	std::string title = "\e[34m";
	std::string reset = "\e[0m";
	
	{
		std::cout << title << "Find value 30 in a vector of 1000 elements" << reset << std::endl;
		int tab[1000];

		srand(time(NULL));
		for (int i = 0; i < 1000; i++)
			tab[i] = rand() % 1000;

		try {
			std::vector<int> myvector(tab, tab + 1000);
			std::cout << (easyfind< std::vector<int> >(myvector, 30)) << std::endl;
		}
		catch (std::bad_alloc const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		catch (std::length_error const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		catch (std::exception const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
	}
	{
		std::cout << std::endl << title << "Find value 55 in a deque of 100 elements" << reset << std::endl;
		int tab[100];

		srand(time(NULL));
		for (int i = 0; i < 100; i++)
			tab[i] = rand() % 200;

		try {
			std::deque<int> mydeque(tab, tab + sizeof(tab) / sizeof(int));
			std::cout << easyfind< std::deque<int> >(mydeque, 55) << std::endl;
		}
		catch (std::bad_alloc const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		catch (std::length_error const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		catch (std::exception const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
	}
	{
		std::cout << std::endl << title << "Find value 10 in a list of 100 elements" << reset << std::endl;
		int tab[100];

		srand(time(NULL));
		for (int i = 0; i < 100; i++)
			tab[i] = rand() % 200;

		try {
			std::list<int> mylist(tab, tab + 100);
			std::cout <<easyfind< std::list<int> >(mylist , 10) << std::endl;
		}
		catch (std::bad_alloc const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		catch (std::length_error const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
		catch (std::exception const & e) {
			std::cerr << "\e[31m" << e.what() << "\e[0m" << std::endl;
		}
	}
	return 0;
}
