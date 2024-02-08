/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:13:39 by galambey          #+#    #+#             */
/*   Updated: 2024/02/08 15:20:04 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

#include <iostream>
#include <string>

class 	Harl {

	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
	public :
		Harl();
		~Harl();
		void	complain(std::string level);
} ;

#endif