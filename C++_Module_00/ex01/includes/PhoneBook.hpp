/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:50:21 by galambey          #+#    #+#             */
/*   Updated: 2024/02/05 10:41:04 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "phone.hpp"

class	PhoneBook
{
	private:
		Contact 	my_contacts[8];
		void		print_title();
		int			get_contact_info(t_info *info);
		std::string	ask_info_loop(std::string output, std::string err_output, int (check)(std::string));
		int 		check_phone(std::string input);
		static int 		check_name(std::string input);
		static int 		check_only_space(std::string input);
		int			search_contact(void);
		int			print_one_contact(int i);
		static int	ft_stoi(std::string s);
	public:
		PhoneBook(); // Construtor
		~PhoneBook(); // Destructor
		int			add_contact(int i);
		int			print_all_contact();

};

#endif