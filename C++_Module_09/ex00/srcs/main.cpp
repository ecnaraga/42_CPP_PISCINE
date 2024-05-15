/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:55:06 by galambey          #+#    #+#             */
/*   Updated: 2024/05/14 14:29:15 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main (int ac , char **av) {
	
	if (ac == 2)
	{
		try
		{
			std::ifstream 	input;
			BitCoinExchange btc;
			
			input.exceptions(std::ifstream::failbit);
			try
			{
				input.open(av[1], std::ifstream::in);
			}
			catch (std::ios_base::failure const & e)
			{
				std::cerr << "Error: could not open file." << std::endl;
				return (1);
			}
			btc.get_input(input);
		}
		catch (std::exception const & e)
		{
			std::cerr << "Error: invalid database file." << std::endl;
		}
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}

/* AUTRE MOYEN DE PROTEGER SI OPEN FAIL : */
// int main (int ac , char **av) {
	
// 	(void) av;
// 	std::ifstream 	input;
// 	BitCoinExchange btc;
	
// 	if (ac == 2)
// 	{
// 		input.open(av[1], std::ifstream::in); // checker si pas les dropits ou file inexistant
// 		if (input.fail()) // ou (!input.good())
// 		{
// 			std::cerr << "Error: could not open file." << std::endl;
// 			return (1);
// 		}
// 		btc.get_input(input);
// 	}
// 	else
// 	{
// 		std::cerr << "Error: could not open file." << std::endl;
// 		return (1);
// 	}
// 	return (0);
// }