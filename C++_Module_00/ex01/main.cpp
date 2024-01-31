/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:14 by galambey          #+#    #+#             */
/*   Updated: 2024/01/31 12:33:48 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"
#include <fstream>

int	ft_stoi(std::string s) {

	int result;
	
	for(int i = 0; s[i]; i++) {
		if (!isdigit(s[i]))
			return (-1);
	}
	std::istringstream(s) >> result;
	return(result);		
}

void print_ten_char(std::string s) {
	
	int test = 1;
	
	if (s.length() > 10)
		test = 2;
	switch (test) {
		case 1 :
			std::cout.width(10);
			std::cout << s;
			break;
		case 2 :
			s.resize(10);
			s[9] = '.';
			std::cout << s;
			break;
	}
}

int error_input(int message)
{
	while (1)
	{
		std::string input;
		if (message == 1)
			std::cout << "Please enter \"y\" to try again, otherwise \"n\" : ";
		else
			std::cout << "Please enter \"h\" to get help, or \"y\" to try again : ";
		getline(std::cin, input);
		if (std::cin.eof())
			return (-1);
		else if (input.empty() || (message == 1 && input != "y" && input != "n") || (message != 1 && input != "y" && input != "h"))
			continue;
		else if (input == "n")
			return (0);
		else if (input == "y")
			return (1);
		else if (input == "h") {
			std::cout << "Phone number must be 2 digits at least and 10 digits at most." << std::endl;
			std::cout << "It can begin with an optional \"+\" at the begining." << std::endl;
			std::cout << "In that case the \"+\" must be followed by 9 digits at least and 14 at most." << std::endl;
			return (1);
		}
	}
}

int	main(void) {
	
	PhoneBook phonebook;
	std::string	rule, index;
	int	i = 0, err = 0;

	while (1)
	{
		if (err == 0)
			std::cout << "Enter a command : ";
		getline(std::cin, rule);
		err = 0;
		if (std::cin.eof())
			return (0);
		else if (rule.empty()) {
			err = 1;
			std::cout << std::endl << "Empty command. Please try again with the followings commands : ADD , SEARCH or EXIT : ";
		}
		else if (rule == "ADD") {
			err = 0;
			if (phonebook.add_contact(i))
				return (0);
			i = (i != 7) * (i + 1);
			std::cout << std::endl;
		}
		else if (rule == "SEARCH") {
			err = 0;
			if (phonebook.print_all_contact())
				return (0);
			std::cout << std::endl;
		}
		else if (rule == "EXIT")
			break ;
		else {
			err = 1;
			std::cout << std::endl << "Unavailable command. Please try again with the followings commands : ADD , SEARCH or EXIT : ";
		}
	}
	return (0);
}

// int main () {
//   std::cout << std::setfill ('x') << std::setw (10);
//   std::cout << 77 << std::endl;
//   return 0;
// }


// int main () {
//   std::cout << std::setw(10);
//   std::cout << 77 << std::endl;
//   return 0;
// }

// int main () {
//   std::cout << 100 << '\n';
//   std::cout.width(10);
//   std::cout << 10 << '\n';
//   std::cout.fill('x');
//   std::cout.width(15);
//   std::cout << std::left << 100 << '\n';
//   return 0;
// }