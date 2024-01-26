/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:00 by galambey          #+#    #+#             */
/*   Updated: 2024/01/26 13:49:27 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include "Contact.hpp"

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

void	Contact::print_contact()
{
	std::cout << this->first_name << this->name << this->nickname << this->phone_number << this->darkest_secret << std::endl;
}