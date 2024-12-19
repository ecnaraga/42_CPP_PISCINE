/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:22 by galambey          #+#    #+#             */
/*   Updated: 2024/06/07 11:41:37 by galambey         ###   ########.fr       */
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
# include <ctime>
# include <unistd.h>

class PmergeMe {
		
	private :

		bool		_parity;
		int			_left;
		int			_ac;
		char 		**_av;
		
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

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class PmergeMeException : public std::exception {
			private :
				const char *_err;
			public :
				PmergeMeException(const char *err);
				const char * what() const throw();	
		} ;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		size_t jacobsthal_suit(int order) const;
		
		template<typename T>
		void	print_container(T & cont, std::string const & message) {
			
			typename T::iterator it;
			
			std::cout.fill(' ');
			std::cout.flags(std::ios::left);
			std::cout.width(10);
			std::cout << message;
			std::cout.width();
			for (it = cont.begin(); it != cont.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		
		/* ***************************************************************** */
		/* ***************************** Vector **************************** */
		/* ***************************************************************** */
		
		void	parse_nb(std::vector<int> & to_sort) const;
		void	make_pair(std::vector<std::pair<int, int> > & pair, std::vector<int> & to_sort);
		void	dichotomic_insertion(std::vector<int> & sorted, std::vector< std::pair<int, int> > * pair, size_t size);
		std::vector<std::pair<int, int> > *rec_sort_hight_elem(std::vector<std::pair<int, int> > & pair, int begin, int end);

		/* ***************************************************************** */
		/* ***************************** Deque ***************************** */
		/* ***************************************************************** */

		void	parse_nb(std::deque<int> & to_sort) const;
		void	make_pair(std::deque<std::pair<int, int> > & pair, std::deque<int> & to_sort);
		void	dichotomic_insertion(std::deque<int> & sorted, std::deque< std::pair<int, int> > * pair, size_t size);
		std::deque<std::pair<int, int> > *rec_sort_hight_elem(std::deque<std::pair<int, int> > & pair, int begin, int end);
		
	public :
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		PmergeMe(int ac, char **av); // a mettre en prive
		~PmergeMe();
		
		/* ***************************************************************** */
		/* ***************************** Vector **************************** */
		/* ***************************************************************** */
		
		void	to_vector();

		/* ***************************************************************** */
		/* ***************************** Deque ***************************** */
		/* ***************************************************************** */

		void	to_deque();
} ;

#endif