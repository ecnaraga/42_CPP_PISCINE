/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:35:11 by galambey          #+#    #+#             */
/*   Updated: 2024/02/08 15:33:43 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void) {
	
	// std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void) {

	// std::cout << "Harl destroyed" << std::endl;
}

void	Harl::debug(void) {
	
	std::cout << "Function's execution successful" << std::endl;
}

void	Harl::info(void) {
	
	std::cout << "Function's execution started" << std::endl;
}

void	Harl::warning(void) {

	std::cout << "Check leaks before exit" << std::endl;	
}

void	Harl::error(void) {
	
	std::cout << "Dynamic allocation failed" << std::endl;
}

void	Harl::complain(std::string level) {
	
	std::string	rules[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int 	l = -1;
	for (int i = 0; i < 4; i++) {
		if (level == rules[i]) {
			l = i;
			break;
		}
	}
	
	void 	(Harl::*f)(void); // Declaration du pointeur f sur une fonction membre de Harl
	switch (l) {
		case 0 :
			f = &Harl::debug; // Stocker l'adresse de la fonction membre dans le pointeur
			(this->*f)(); // Appelle la fonction membre stockee
			break ;
		case 1 :
			f = &Harl::info;
			(this->*f)();
			break ;
		case 2 :
			f = &Harl::warning;
			(this->*f)();
			break ;
		case 3 :
			f = &Harl::error;
			(this->*f)();
			break ;
		default :
			break ;
	}
}

// /* OTHER WAY */
// void	Harl::complain(std::string level) {
	
// 	std::string	rules[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
// 	for (int i = 0; i < 4; i++) {
// 		if (level == rules[i]) {
// 			(this->*f[i])();
// 			break;
// 		}
// 	}
// }
