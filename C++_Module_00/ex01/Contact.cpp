/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:00 by galambey          #+#    #+#             */
/*   Updated: 2024/01/30 15:15:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

Contact::Contact(){
	// std::cout << "Contact created" << std::endl;
}

Contact::~Contact(){
	// std::cout << "Contact destructed" << std::endl;
}

Contact Contact::add_contact(t_info info)
{
	Contact new_contact;
	
	new_contact.first_name = info.f_name;
	new_contact.name = info.l_name;
	new_contact.nickname = info.n_name;
	new_contact.phone_number = info.phone;
	new_contact.darkest_secret = info.secret;
	return (new_contact);
}

void	Contact::print_contact(int index)
{
	std::string tmp;
	
	if (this->first_name.length())
	{
		std::cout.width(10);
		std::cout << index << "|";
		print_ten_char(this->first_name);
		std::cout << "|";
		print_ten_char(this->name);
		std::cout << "|";
		print_ten_char(this->nickname);
		std::cout << std::endl;
		return ;
	}
}

int	Contact::print_contact_infos(int index)
{
	if (this->first_name.length())
	{
		std::cout << this->first_name << std::endl;
		std::cout << this->name << std::endl;
		std::cout << this->nickname << std::endl;
		std::cout << this->phone_number << std::endl;
		std::cout << this->darkest_secret << std::endl;
		return (0);
	}
	std::cout << "Contact " << index << " is empty. ";
	return (error_input(1));
	// while (1)
	// {
	// 	std::string input;
	// 	std::cout << "Please enter 0 to go back or 1 to try again : ";
	// 	getline(std::cin, input);
	// 	if (std::cin.eof())
	// 		return (-1);
	// 	else if (input.empty() || (input != "0" && input != "1"))
	// 		continue;
	// 	else if (input == "0")
	// 		return (0);
	// 	else if (input == "1")
	// 		return (1);
	// }
	// return (1);
}
