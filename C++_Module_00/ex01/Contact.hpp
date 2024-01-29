/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:50:39 by galambey          #+#    #+#             */
/*   Updated: 2024/01/29 14:23:29 by galambey         ###   ########.fr       */
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
		
		Contact add_contact(t_info info);
		void	print_contact(int index);
		void	print_contact_infos(int index);
};

#endif