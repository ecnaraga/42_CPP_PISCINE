/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:50:21 by galambey          #+#    #+#             */
/*   Updated: 2024/01/31 12:12:54 by galambey         ###   ########.fr       */
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

		void		print_title();
		int			add_contact(int i);
		int			get_contact_info(t_info *info);
		std::string	ask_info_loop(std::string output, std::string err_output, int (check)(std::string));
		int 		check_phone(std::string input);
		static int 		check_name(std::string input);
		static int 		check_only_space(std::string input);
		int			print_all_contact();
		int			search_contact(void);
		int			print_one_contact(int i);

};

#endif