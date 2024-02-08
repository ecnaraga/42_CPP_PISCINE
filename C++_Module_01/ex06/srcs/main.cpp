/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:31:10 by galambey          #+#    #+#             */
/*   Updated: 2024/02/08 15:35:43 by galambey         ###   ########.fr       */
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
	return (0);
}