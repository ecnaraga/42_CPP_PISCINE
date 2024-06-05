/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:22 by galambey          #+#    #+#             */
/*   Updated: 2024/05/29 19:17:29 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <utility>
# include <algorithm>

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
		size_t jacobsthal_suit() const;
		void	dichotomic_insertion(std::vector< std::pair<int,int> > & v_p);
		void	rec_sort_hight_elem(std::vector< std::pair<int, int> > & v_p, std::vector< std::pair<int, int> >::iterator & it);
		void	to_vector();
} ;

#endif