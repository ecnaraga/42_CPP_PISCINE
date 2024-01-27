/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:50:39 by galambey          #+#    #+#             */
/*   Updated: 2024/01/27 11:02:23 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "phone.hpp"

class Contact
{
	private:							// Access Specifiers = private => on retrouvera les attributs prives de la classe
		std::string first_name;
		std::string name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		
	public:								// Access Specifiers = public => on retrouvera les attributs publics de la classe
		Contact();
		~Contact();
		
		Contact add_contact(std::string f_name, std::string l_name,std::string n_name,std::string phone, std::string secret); 						// Construtor
		void	print_contact(int index);
		void	print_contact_infos(int index);
};

#endif