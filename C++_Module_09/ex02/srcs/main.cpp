/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:44:28 by galambey          #+#    #+#             */
/*   Updated: 2024/06/06 18:37:10 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int ac, char** av) {
	if (ac < 3)
	{
		std::cerr << "Error : At least two arguments required" << std::endl;
		return (1);
	}
	clock_t	begin;
	clock_t	end;
	float time_v;
	{
		try {
			begin = clock();
			PmergeMe a(ac, av);
			a.to_vector();
			end = clock();
			time_v = (static_cast<float>(end - begin) / CLOCKS_PER_SEC) * 100000;
		}
		catch (std::bad_alloc & e) {
			std::cerr << "Error : Dynamic allocation failed : " << e.what() << std::endl; }
		catch (std::out_of_range const & e) {
			std::cerr << "Error : Out of range : " << e.what() << std::endl; }
		catch (std::length_error const & e) {
			std::cerr << "Error : Lenght error : " << e.what() << std::endl; }
		catch (std::exception const & e) {
			std::cerr << e.what() << std::endl; 
			return (1);}
	}
	try {
		begin = clock();
		PmergeMe a(ac, av);
		a.to_deque();
		end = clock();
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : ";
		std::cout << time_v << " us." << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : ";
		std::cout << (static_cast<float>(end - begin) / CLOCKS_PER_SEC) * 100000 << " us." << std::endl;
		
	}
	catch (std::bad_alloc & e) {
		std::cerr << "Error : Dynamic allocation failed : " << e.what() << std::endl; }
	catch (std::out_of_range const & e) {
		std::cerr << "Error : Out of range : " << e.what() << std::endl; }
	catch (std::length_error const & e) {
		std::cerr << "Error : Lenght error : " << e.what() << std::endl; }
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl; }
	return (0);
}
