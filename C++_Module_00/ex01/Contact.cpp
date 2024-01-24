/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:00 by galambey          #+#    #+#             */
/*   Updated: 2024/01/24 16:37:49 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include "Contact.hpp"

Contact::Contact(std::string f_name, std::string l_name,std::string n_name,std::string phone, std::string secret)
{
	first_name = f_name;
	name = l_name;
	n_name = nickname;
	phone_number = phone;
	darkest_secret = secret;
}
