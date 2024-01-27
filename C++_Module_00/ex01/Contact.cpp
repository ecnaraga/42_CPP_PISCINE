/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:00 by galambey          #+#    #+#             */
/*   Updated: 2024/01/27 11:02:37 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

Contact::Contact(){}

Contact::~Contact(){}

Contact Contact::add_contact(std::string f_name, std::string l_name,std::string n_name,std::string phone, std::string secret)
{
	Contact new_contact;
	
	new_contact.first_name = f_name;
	new_contact.name = l_name;
	new_contact.nickname = n_name;
	new_contact.phone_number = phone;
	new_contact.darkest_secret = secret;
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

void	Contact::print_contact_infos(int index)
{
	if (this->first_name.length())
	{
		std::cout << this->first_name << std::endl;
		std::cout << this->name << std::endl;
		std::cout << this->nickname << std::endl;
		std::cout << this->phone_number << std::endl;
		std::cout << this->darkest_secret << std::endl;
		return ;
	}
	std::cout << "Contact " << index << " is empty" << std::endl;
}
