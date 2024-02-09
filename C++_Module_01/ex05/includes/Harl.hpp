/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:57:52 by galambey          #+#    #+#             */
/*   Updated: 2024/02/09 14:45:47 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string.h>


class Harl {
	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
} ;

// typedef void (Harl::*pf)(void);
#endif