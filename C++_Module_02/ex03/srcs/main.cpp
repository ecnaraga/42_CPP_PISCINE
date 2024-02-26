/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:41:05 by galambey          #+#    #+#             */
/*   Updated: 2024/02/23 17:52:45 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main(void) {
	
	{
		Point a(0.0f, 0.0f);
		Point b(10.0f, 0.0f);
		Point c(0.0f, 10.0f);
		Point m(2.0f, 3.0f);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(1.0f, 0.0f);
		Point c(0.0f, 2.0f);
		Point m(15.0f, 15.0f);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(1.0f, 0.0f);
		Point c(0.0f, 2.0f);
		Point m(0.0f, 0.0f);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	{
		Point a(-2.08f, -60.40f);
		Point b(1.0f, 0.0f);
		Point c(15.5f, 20.30f);
		Point m(15.5f, 20.30f);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	{
		Point a(0.05f, 10.40f);
		Point b(0.05f, 0.0f);
		Point c(15.5f, 20.30f);
		Point m(0.05f, 2.0f);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	{
		Point a(0.05f, -10.40f);
		Point b(0.05f, 0.0f);
		Point c(15.5f, 20.30f);
		Point m(0.05f, -2.0f);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	{
		Point a(0, 2);
		Point b(2, 0);
		Point c(0, 0);
		Point m(1, 1);

		if (bsp(a, b, c, m))
			std::cout << "Le point appartient au triangle ABC" << std::endl;
		else
			std::cout << "Le point n'appartient pas au triangle ABC" << std::endl;
	}
	
	return (0);
}
