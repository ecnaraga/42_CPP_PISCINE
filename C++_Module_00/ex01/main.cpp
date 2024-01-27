/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:14 by galambey          #+#    #+#             */
/*   Updated: 2024/01/27 11:31:09 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

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

int	main(void) {
	
	PhoneBook phonebook;
	Contact	  new_friend;
	std::string	rule, index, f_name, l_name, n_name, phone, secret;
	int	i = 0;

	while (1)
	{
		std::cin >> rule;
		if (std::cin.eof())
			return (0); // ou continue ; ? voir avec remi ce qu il en pense
		if (rule == "ADD")
		{
			std::cout << "First name : ";
			std::cin >> f_name;
			if (std::cin.eof())
				return (0);
			std::cout << "Last name : ";
			std::cin >> l_name;
			if (std::cin.eof())
				return (0);
			std::cout << "Nickname : ";
			std::cin >> n_name;
			if (std::cin.eof())
				return (0);
			std::cout << "Phone number : ";
			std::cin >> phone;
			if (std::cin.eof())
				return (0);
			std::cout << "Darkest secret : ";
			std::cin >> secret;
			if (std::cin.eof())
				return (0);
			new_friend = new_friend.add_contact(f_name, l_name, n_name, phone, secret);
			phonebook.add_contact(i, new_friend);
			i = (i != 7) * (i + 1);
			std::cout << i << std::endl;
		}
		if (rule == "SEARCH")
		{
			int j;
			phonebook.print_all_contact();
			std::cout << "Enter the contact's index you whish to consult : ";
			while (1)
			{
				std::cin >> index;
				if (std::cin.eof())
					return (0);
				j = ft_stoi(index);
				int res = phonebook.print_one_contact(j);
				if (res == 0)
					break ;
			}
		}
		if (rule == "EXIT")
			break ;
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