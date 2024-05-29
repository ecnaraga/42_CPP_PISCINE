/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:22 by galambey          #+#    #+#             */
/*   Updated: 2024/05/26 09:09:15 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <utility>

class PmergeMe {
		
	private :

		std::string _suit;
		bool		_parity;
		int			_left;
		// std::vector< int >	_my_vect;
		std::vector< int >	_my_vect;
		std::list< int >	_my_list;
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		PmergeMe();
		PmergeMe(PmergeMe & orig);
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		PmergeMe & operator=(PmergeMe & rhs);
		
	public :
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		PmergeMe(std::string & s);
		~PmergeMe();
		
		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class OverflowException : public std::exception {
			const char * what() const throw();	
		} ;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void	swap_elem(std::vector< std::pair<int, int> >::iterator & elem1, std::vector< std::pair<int, int> >::iterator & elem2);
		void	sort_pair(std::pair<int, int> * p);
		unsigned long long int jacobsthal_suit() const;
		void	rec_sort_hight_elem(std::vector< std::pair<int, int> > & v_p, std::vector< std::pair<int, int> >::iterator & it);
		void	to_vector();
} ;

#endif