/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:40 by galambey          #+#    #+#             */
/*   Updated: 2024/02/03 10:42:28 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
	private :
		std::string name;
	
	public :
		Zombie(void); // Constructeur par default
		~Zombie();
		Zombie(std::string name); // 2eme constructeur
		void announce(void);
} ;

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif