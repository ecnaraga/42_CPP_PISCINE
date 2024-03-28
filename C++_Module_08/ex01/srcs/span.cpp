/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:39:26 by galambey          #+#    #+#             */
/*   Updated: 2024/03/28 18:36:40 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

	Span::Span() : _size_max(0) {};
	
	Span::Span(Span const & orig) : _size_max(orig._size_max) {
		*this = orig;
	};
	
	Span::Span(unsigned int N) : _size_max(N) {
		this->_nb_elem = 0;
	}
	
	Span::~Span() {};

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Span &	Span::operator=(Span const & rhs) {
	this->_nb_elem = rhs._nb_elem;
	this->_span = rhs._span;
	return *this;
}
/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char * Span::SpanAlreadyFullException::what() const throw() {
	return ("Span is already full");
}

const char * Span::NotFoundValueException::what() const throw() {
	return ("Value is not stocked in Span");
}
/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void	Span::addNumber(int nb) {
	
	if (this->_nb_elem >= this->_size_max)
		throw (SpanAlreadyFullException());
	std::vector<int>::iterator it;
	// if (this->_nb_elem == 0)
	// 	it = this->_span.begin();
	// else
		it = this->_span.end();
	this->_span.insert(it, nb);
}

/* ATTENTION LE PLUS PETIT OU MAX SPAN EST LA DISTANCE ENTRE DEUX NB ET NON LE MIN OU MAX ELEM*/
/* int	Span::shortestSpan() const {
	return (*std::min_element(this->_span.begin(), this->_span.end()));
}

int Span::longestSpan() const {
	return (*std::max_element(this->_span.begin(), this->_span.end()));
} */