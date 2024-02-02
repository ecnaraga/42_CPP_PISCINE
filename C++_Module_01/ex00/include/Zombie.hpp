/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:40 by galambey          #+#    #+#             */
/*   Updated: 2024/02/02 17:30:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
	private :
		std::string name;
	
	public :
		Zombie(void);
		~Zombie();
		Zombie(std::string name);
		void name_zombie(std::string name);
		void announce(void);
} ;

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif