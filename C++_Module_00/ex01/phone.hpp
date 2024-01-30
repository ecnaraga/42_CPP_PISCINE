/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:13:16 by garance           #+#    #+#             */
/*   Updated: 2024/01/30 16:50:08 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

typedef struct s_info {
	std::string f_name, l_name, n_name, phone, secret;
}		t_info;

# include "Contact.hpp"
# include "PhoneBook.hpp"

void print_ten_char(std::string s);
int error_input(int message);
int	ft_stoi(std::string s);

#endif