/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:16:38 by galambey          #+#    #+#             */
/*   Updated: 2024/02/08 15:40:48 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void) {

	std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void) {

	std::cout << "Harl destroyed" << std::endl;
}

void	Harl::debug(void) {
	
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "Function's execution successful" << std::endl << std::endl;
}

void	Harl::info(void) {
	
	std::cout << "[INFO]" << std::endl;
	std::cout << "Function's execution started" << std::endl << std::endl;
}

void	Harl::warning(void) {

	std::cout << "[WARNING]" << std::endl;
	std::cout << "Check leaks before exit" << std::endl << std::endl;	
}

void	Harl::error(void) {
	
	std::cout << "[ERROR]" << std::endl;
	std::cout << "Dynamic allocation failed" << std::endl << std::endl;
}

void	Harl::complain(std::string level) {
	
	std::string rule[4] = {"DEBUG", "INFO", "WARNING", "LEVEL"};
	int l = -1;

	for (int i = 0; i < 4; i++) {
		if (level == rule[i]) {
			l = i;
		}
	}
	
	void (Harl::*f)(void);
	switch (l) {
		case 0 :
			f = &Harl::debug;
			(this->*f)();
		case 1 :
			f = &Harl::info;
			(this->*f)();
		case 2 :
			f = &Harl::warning;
			(this->*f)();
		case 3 :
			f = &Harl::error;
			(this->*f)();
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
