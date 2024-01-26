/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:50:21 by galambey          #+#    #+#             */
/*   Updated: 2024/01/26 16:57:12 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact my_contacts[8];
	public:
		PhoneBook(); // Construtor
		~PhoneBook(); // Destructor

		void	add_contact(int i, Contact contact);
		void	print_all_contact();
		void	print_one_contact(int i);
		// Contact add_contact(std::string f_name, std::string l_name,std::string n_name,std::string phone, std::string secret); 						// Construtor

};

#endif