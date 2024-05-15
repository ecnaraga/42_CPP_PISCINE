/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:22 by galambey          #+#    #+#             */
/*   Updated: 2024/05/15 16:26:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

class PmergeMe {
	private :

		class	Pair {
			private :
				int _large;
				int _small;
				
				Pair();
				Pair(Pair & orig);
				Pair & operator=(Pair & rhs);
				
			public :
				Pair(int n1, int n2);
				~Pair();
				
		} ;
		
		std::string _suit;
		std::vector<Pair>	_my_vect;
		std::list<Pair>		_my_list;
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		PmergeMe();
		PmergeMe(PmergeMe & orig);
		~PmergeMe();
		
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
		
		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class OverflowException : public std::exception {
			const char * what() const throw();	
		} ;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		static unsigned long long int jacobsthal_suit()/*  const */;
		void	to_vector()
} ;

#endif