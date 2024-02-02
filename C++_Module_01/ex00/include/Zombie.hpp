/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:40 by galambey          #+#    #+#             */
/*   Updated: 2024/02/02 15:26:50 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	
	private :
		std::string name;
	
	public :
		Zombie(void);
		~Zombie(void);
		void name_zombie(std::string name);
		void announce(void);
} ;

#endif