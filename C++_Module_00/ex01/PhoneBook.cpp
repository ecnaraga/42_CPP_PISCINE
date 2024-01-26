/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:04 by galambey          #+#    #+#             */
/*   Updated: 2024/01/26 16:59:00 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void PhoneBook::add_contact(int i, Contact contact)
{
	this->my_contacts[i] = contact;
	contact.print_contact();
}

void PhoneBook::print_all_contact()
{
	Contact contact;
	
	for(int i = 0; i < 8; i++)
	{
		contact = this->my_contacts[i];
		contact.print_contact();
	}
}

void PhoneBook::print_one_contact(int i)
{
	Contact contact;
	
	if (i >= 0 && i < 8)
	contact = this->my_contacts[i];
	contact.print_contact();
}
