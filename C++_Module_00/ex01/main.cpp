/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:14 by galambey          #+#    #+#             */
/*   Updated: 2024/01/26 18:30:30 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"
# include "PhoneBook.hpp"
#include <sstream>

int	ft_ctoi(std::string s)
{
	std::istringstream index;
	int result;
	
	if (s.length() != 1 || !isdigit(s[0]))
		return(-1);
	index.str(s);
	index >> result;
	return(result);		
}

int	main(void){
	
	PhoneBook phonebook;
	// Contact	  new_friend;
	std::string	rule, index, f_name, l_name, n_name, phone, secret;
	int	i = 0;

	// new_friend = new_friend.add_contact("a", "b", "c", "d", "e");
	// new_friend.print_contact();
	// phonebook.add_contact(0, new_friend);

	while (1)
	{
		std::cin >> rule;
		if (rule == "ADD")
		{
			Contact	  new_friend;
			std::cout << "First name : ";
			std::cin >> f_name;
			std::cout << "Last name : ";
			std::cin >> l_name;
			std::cout << "Nickname : ";
			std::cin >> n_name;
			std::cout << "Phone number : ";
			std::cin >> phone;
			std::cout << "Darkest secret : ";
			std::cin >> secret;
			new_friend = new_friend.add_contact(f_name, l_name, n_name, phone, secret);
			// i = (i == 8) * 0 + (i != 8) * (i + 1);
			// i = (i != 8) * (i + 1);
			// if (i == 8)
			// 	i = 0;
			// else
				i++;
		}
		if (rule == "SEARCH")
		{
			int j;
			phonebook.print_all_contact();
			std::cout << "Enter the contact's index you whish to consult : ";
			std::cin >> index;
			j = ft_ctoi(index);
			phonebook.print_one_contact(j);
		}
		if (rule == "QUIT")
			break ;
	}
	return (0);
}


// istringstream::str
// #include <string>       // std::string
// #include <iostream>     // std::cout
// #include <sstream>      // std::istringstream

// int main () {
//   std::istringstream iss;
//   std::string strvalues = "32 240 2 1450";

//   iss.str (strvalues);

//   for (int n=0; n<4; n++)
//   {
//     int val;
//     iss >> val; // JE NE COMPREND PAS CETTE LIGNE
//     std::cout << val << '\n';
//   }
//   std::cout << "Finished writing the numbers in: ";
//   std::cout << iss.str() << '\n';
//   return 0;
// }