/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:14 by galambey          #+#    #+#             */
/*   Updated: 2024/01/29 14:25:20 by galambey         ###   ########.fr       */
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

int	ft_add_contact(t_info *info) {
	std::cout << "First name : ";
	std::cin >> info->f_name;
	if (std::cin.eof())
		return (1);
	std::cout << "Last name : ";
	std::cin >> info->l_name;
	if (std::cin.eof())
		return (1);
	std::cout << "Nickname : ";
	std::cin >> info->n_name;
	if (std::cin.eof())
		return (1);
	std::cout << "Phone number : ";
	std::cin >> info->phone;
	if (std::cin.eof())
		return (1);
	std::cout << "Darkest secret : ";
	std::cin >> info->secret;
	if (std::cin.eof())
		return (1);
	return (0);
}

int	main(void) {
	
	PhoneBook phonebook;
	Contact	  new_friend;
	t_info info;
	std::string	rule, index;
	int	i = 0;

	while (1)
	{
		std::cout << "Enter a command : ";
		std::cin >> rule;
		if (std::cin.eof())
			return (0);
		if (rule == "ADD")
		{
			if (ft_add_contact(&info))
				return (0);
			new_friend = new_friend.add_contact(info);
			phonebook.add_contact(i, new_friend);
			i = (i != 7) * (i + 1);
			std::cout << i << std::endl;
		}
		if (rule == "SEARCH")
		{
			int j;
			phonebook.print_all_contact();
			std::cout << "Enter the contact's index you whish to consult : ";
			while (1) {
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