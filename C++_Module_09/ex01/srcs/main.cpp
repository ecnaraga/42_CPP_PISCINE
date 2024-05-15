/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:44 by galambey          #+#    #+#             */
/*   Updated: 2024/05/15 11:41:24 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::string expression = av[1];
	try
	{
		RPN::calcul_expression(expression);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1); 
	}
	return (0);
}
