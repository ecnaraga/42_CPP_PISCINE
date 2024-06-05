/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:22 by galambey          #+#    #+#             */
/*   Updated: 2024/06/05 16:38:57 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <utility>
# include <algorithm>

class PmergeMe {
		
	private :

		bool		_parity;
		int			_left;
		std::vector< int >	_my_vect;
		
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

		PmergeMe(int ac, char **av);
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

		// void	swap_elem(std::vector< std::pair<int, int> >::iterator & elem1, std::vector< std::pair<int, int> >::iterator & elem2);
		// void	sort_pair(std::pair<int, int> * p);
		size_t	make_pair(std::pair<int, int> * pair);
		size_t jacobsthal_suit(int order) const;
		void	dichotomic_insertion(std::vector<int> & sorted, std::pair<int,int> * pair, size_t size);
		std::pair<int, int> *rec_sort_hight_elem(std::pair<int, int> * pair, int begin, int end);
		int *	rec_sort_hight_elem(int  pair[], int begin, int end);
		void	rec_sort_hight_elem(int  pair[], int sorted_pair[], int begin, int end);
		// void	rec_sort_hight_elem(std::pair<int, int> * pair, std::pair<int, int> * sorted_pair, int begin, int end);
		// std::pair<int, int> *	PmergeMe::rec_sort_hight_elem(std::pair<int, int> * pair, int begin, int end);
		void	to_vector();
		void	to_deque();
		void	dichotomic_insertion(std::deque<int> & sorted, std::pair<int,int> * pair, size_t size);
} ;

#endif