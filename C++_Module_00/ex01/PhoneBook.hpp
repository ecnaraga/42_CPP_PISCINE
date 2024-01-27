/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:50:21 by galambey          #+#    #+#             */
/*   Updated: 2024/01/27 11:05:08 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "phone.hpp"

class	PhoneBook
{
	private:
		Contact my_contacts[8];
	public:
		PhoneBook(); // Construtor
		~PhoneBook(); // Destructor

		void	add_contact(int i, Contact contact);
		void	print_all_contact();
		int	print_one_contact(int i);

};

#endif