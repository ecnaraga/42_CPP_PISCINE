/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:04 by galambey          #+#    #+#             */
/*   Updated: 2024/02/05 10:56:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phone.hpp"

PhoneBook::PhoneBook(){

	print_title();
	// std::cout << "Phonebook created" << std::endl;
}

PhoneBook::~PhoneBook(){

	// std::cout << "Phonebook destroyed" << std::endl;
}

void PhoneBook::print_title() {
	
	std::cout << std::endl;
	std::cout << "	█████ ▌   ▐ █████ █   ▐ █████ █████ █████ █████ ▌   █" << std::endl;
	std::cout << "	▌   ▐ ▌   ▐ ▌   ▐ ▌█  ▐ ▌     ▌   ▐ ▌   ▐ ▌   ▐ ▌  █" << std::endl;
	std::cout << "	█████ █████ ▌   ▐ ▌ █ ▐ █████ █████ ▌   ▐ ▌   ▐ ███" << std::endl;
	std::cout << "	▌     ▌   ▐ ▌   ▐ ▌  █▐ ▌     ▌   ▐ ▌   ▐ ▌   ▐ ▌  █" << std::endl;
	std::cout << "	▌     ▌   ▐ █████ ▌   █ █████ █████ █████ █████ ▌   █" << std::endl << std::endl;
}

int PhoneBook::check_phone(std::string input)
{
	if ((input[0] != '+' && (input[0] < '0' || input[0] > '9'))
		|| (input[0] != '+' && input.length() > 10)
		|| input.length() > 15 || input.length() < 2
		|| (input[0] == '+' && input.length() < 10))
		return (1);
	for(int i = 1; input[i]; i++) {
		if (!isdigit(input[i]))
			return (1);
	}
	return (0);
}

int PhoneBook::check_name(std::string input)
{
	for (int i = 0; input[i]; i++) {
		if (input[i] == '-' && i > 0 && input[i - 1] != '-' && input[i + 1])
			continue ;
		if (!isalpha(input[i]))
			return (1);
	}
	return (0);
}

int PhoneBook::check_only_space(std::string input)
{
	for (int i = 0; input[i]; i++) {
		if (!isblank(input[i]))
			return (0);
	}
	return (1);
}

/* RULE ADD */

std::string	PhoneBook::ask_info_loop(std::string output, std::string err_output, int (check)(std::string)) {
	
	std::string input;
	
	while (1) {
		std::cout << output;
		getline(std::cin, input);
		if (std::cin.eof()) {
			input = "";
			return (input);
		}
		if (input.empty() || check(input)) {
			std::cout << err_output;
			continue ;
		}
		return (input);
	}
}

int	PhoneBook::get_contact_info(t_info *info) {

	int err = 0;
	
	info->f_name = ask_info_loop("First name : ",
		"Field must be completed whith alphabetic characters (\"-\" is allowed for composed name). Please try again. ", check_name);
	if(info->f_name.empty())
		return (1);

	info->l_name = ask_info_loop("Last name : ",
		"Field must be completed whith alphabetic characters (\"-\" is allowed for composed name). Please try again. ", check_name);
	if(info->l_name.empty())
		return (1);
	
	info->n_name = ask_info_loop("Nickname : ",
		"Field must be completed whith alphabetic characters (\"-\" is allowed for composed name). Please try again. ", check_name);
	if(info->n_name.empty())
		return (1);

	while (1) {
		std::cout << "Phone number : ";
		getline(std::cin, info->phone);
		if (std::cin.eof())
			return (1);
		if (info->phone.empty()) {
			std::cout << "Field must be completed. Please try again. ";
			continue ;
		}
		err = check_phone(info->phone);
		if (err == 0)
			break ;
		std::cout << "Wrong format. ";
		error_input(2);
	}
	
	info->secret = ask_info_loop("Darkest secret : ", "Field must be completed. Please try again. ", check_only_space);
	if(info->secret.empty())
		return (1);
	return (0);
}

int	PhoneBook::add_contact(int i) {
	
	Contact	  new_friend;
	t_info info;
	
	if (get_contact_info(&info))
		return (1);
	new_friend = new_friend.add_contact(info);
	this->my_contacts[i] = new_friend;
	return (0);
}

/* RULE SEARCH */

int PhoneBook::print_one_contact(int i) {
	
	Contact contact;
	std::string input;
	
	if (i >= 0 && i <= 7) {
		contact = this->my_contacts[i];
		return (contact.print_contact_infos(i));
	}
	std::cout << "Index has to be a digit between 0 and 7. ";
	return (error_input(1));
}

int	PhoneBook::ft_stoi(std::string s) {

	int result;
	
	for(int i = 0; s[i]; i++) {
		if (!isdigit(s[i]))
			return (-1);
	}
	std::istringstream(s) >> result;
	return(result);		
}

int PhoneBook::search_contact(void) {
	
	std::string	index;
	
	while (1) {
		std::cout << "Enter the contact's index you whish to consult : ";
		getline(std::cin, index);
		if (std::cin.eof())
			return (1);
		int res = print_one_contact(ft_stoi(index));
		if (res == 0)
			break ;
	}
	return (0);
}

int PhoneBook::print_all_contact() {
	
	Contact contact;
	
	std::cout << std::endl;
	std::cout << "╔══════════╦══════════╦══════════╦══════════╗" << std::endl;
	std::cout << "║     INDEX║FIRST NAME║ LAST NAME║  NICKNAME║" << std::endl;
	contact = this->my_contacts[0];
	if (contact.test_exist())
		std::cout << "╠══════════╬══════════╬══════════╬══════════╣" << std::endl;
	for(int i = 0; i < 8; i++)
	{
			contact.print_contact(i);
			if (i < 7)
				contact = this->my_contacts[i + 1];
			if (i == 7 || !contact.test_exist()) {
				std::cout << "╚══════════╩══════════╩══════════╩══════════╝" << std::endl;
				break ;
			}
			std::cout << "╟──────────╫──────────╫──────────╫──────────╢" << std::endl;
	}
	std::cout << std::endl;
	if (search_contact())
		return (1);
	return (0);
}
