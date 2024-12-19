/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:44 by galambey          #+#    #+#             */
/*   Updated: 2024/06/07 11:20:12 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::string expression = av[1];
	try
	{
		RPN::calcul_expression(expression);
	}
	catch(std::bad_alloc const & e)
	{
		std::cerr << "Error : dynamic allocation failed : " << e.what() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
		return (1); 
	}
	return (0);
}
