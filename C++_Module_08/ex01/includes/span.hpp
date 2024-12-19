/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:55:59 by galambey          #+#    #+#             */
/*   Updated: 2024/03/29 16:01:38 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <algorithm>

class Span {
	
	private :

		unsigned int const _size_max;
		unsigned int _nb_elem;
		std::vector<int> _span;
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Span();
		
		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class MaxSizeExceededException : public std::exception {
			const char * what() const throw();
		};
		
		class NoSpanPossibleException : public std::exception {
			const char * what() const throw();
		};
		
		class SpanAlreadyFullException : public std::exception {
			const char * what() const throw();
		};
		
	public :
	
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Span(Span const & orig);
		Span(unsigned int N);
		~Span();

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Span & operator=(Span const & rhs);
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void	addNumber(int nb);
		void	addNumber(int nb[], unsigned int size);

		template<typename T>
		void	addNumber(T nb) {
			if (nb.size() > this->_size_max - this->_nb_elem)
				throw(SpanAlreadyFullException());
			try {
				this->_span.insert(_span.begin() + this->_nb_elem, nb.begin(), nb.end());
				this->_nb_elem += nb.size();
			}
			catch (std::bad_alloc const & e) {
				throw ;
			}
		}
		
		int		shortestSpan() const;
		int		longestSpan() const;
} ;

#endif

/*
Implementer dans la class Span, le foreach ne compilera pas car : 
-> On peut utiliser le pointeur this et les fonction membre static ou non dans
	la fonction membre template
-> MAIS : std::for_each n etant pas une fonction membre elle n'a plus acces au pointeur
	this donc ne peut pas appeler une fonction utilisant potentiellement le pointeur this


template<typename T>
void	addNumberMultiply(T nb) {
	(void) nb;
	this->_nb_elem = 0;
	typename T::iterator it = nb.begin();
	this->addNumber(*it); // compile
	std::for_each(nb.begin(), nb.end(), void (*addNumber)(int));	// ne compile pas
}
*/