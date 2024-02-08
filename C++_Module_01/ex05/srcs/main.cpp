/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:35:17 by galambey          #+#    #+#             */
/*   Updated: 2024/02/08 14:00:32 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int ac, char **av) {
	
	if (ac != 2) {
		std::cout << "Wrong parameters." << std::endl;
		return (1);
	}	
	Harl harl;
	harl.complain(av[1]);
}