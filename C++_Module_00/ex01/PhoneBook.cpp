/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:04 by galambey          #+#    #+#             */
/*   Updated: 2024/01/29 14:02:28 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

PhoneBook::PhoneBook(){
	std::cout << "Phonebook created" << std::endl;
}

PhoneBook::~PhoneBook(){
	std::cout << "Phonebook destructed" << std::endl;
}

void PhoneBook::add_contact(int i, Contact contact)
{
	this->my_contacts[i] = contact;
}

void PhoneBook::print_all_contact()
{
	Contact contact;
	
	for(int i = 0; i < 8; i++)
	{
		contact = this->my_contacts[i];
		contact.print_contact(i);
	}
}

int PhoneBook::print_one_contact(int i)
{
	Contact contact;
	
	if (i >= 0 && i < 7) {
		contact = this->my_contacts[i];
		contact.print_contact_infos(i);
		return (0);
	}
	std::cout << "Index has to be a digit between 0 and 7. Please try again : ";
	return (1);
}
