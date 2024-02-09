/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:00 by galambey          #+#    #+#             */
/*   Updated: 2024/02/05 10:47:29 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phone.hpp"

Contact::Contact(){
	// std::cout << "Contact created" << std::endl;
}

Contact::~Contact(){
	// std::cout << "Contact destroyed" << std::endl;
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

void Contact::print_ten_char(std::string s) {
	
	int test = 1;
	
	if (s.length() > 10)
		test = 2;
	switch (test) {
		case 1 :
			// std::cout.width(10); // other way
			std::cout << std::setw(10);
			std::cout << s;
			break;
		case 2 :
			s.resize(10);
			s[9] = '.';
			std::cout << s;
			break;
	}
}

int		Contact::test_exist(void)
{
	if (this->first_name.empty())
		return (0);
	return (1);
}

void	Contact::print_contact(int index)
{
	std::string tmp;
	
	if (this->first_name.length())
	{
		std::cout << "║";
		// std::cout.width(10); // other way
		std::cout << std::setw(10);
		std::cout << index << "║";
		print_ten_char(this->first_name);
		std::cout << "║";
		print_ten_char(this->name);
		std::cout << "║";
		print_ten_char(this->nickname);
		std::cout << "║" << std::endl;
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
}
