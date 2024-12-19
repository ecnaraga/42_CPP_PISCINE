/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:39:26 by galambey          #+#    #+#             */
/*   Updated: 2024/05/30 13:34:57 by galambey         ###   ########.fr       */
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
		// if (this->_size_max > this->_span.max_size()) // pas necessaire car la taille max d un vecteur ne depasse pas la taille max d un unsigned int
		// 	throw(MaxSizeExceededException());
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

const char * Span::MaxSizeExceededException::what() const throw() {
	return ("Span can't be constructed due to a too high size");
}

const char * Span::SpanAlreadyFullException::what() const throw() {
	return ("Span is already full");
}

const char * Span::NoSpanPossibleException::what() const throw() {
	return ("There is less than 2 values stocked");
}
/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void	Span::addNumber(int nb) {
	
	if (this->_nb_elem >= this->_size_max)
		throw (SpanAlreadyFullException());
	std::vector<int>::iterator it = this->_span.end();
	try {
		this->_span.insert(it, nb);
		this->_nb_elem += 1;
	}
	catch (std::bad_alloc const & e) {
		throw ;
	}
}

void	Span::addNumber(int nb[], unsigned int size) {
	
	if (size > this->_size_max - this->_nb_elem)
		throw(SpanAlreadyFullException());
	try {
		this->_span.insert(_span.begin() + this->_nb_elem, nb, nb + size);
		this->_nb_elem += size;
	}
	catch (std::bad_alloc const & e) {
		throw ;
	}
}

int	Span::shortestSpan() const {
	try {
		int span = longestSpan();
		std::vector<int> myvector = this->_span;
		
		std::sort (myvector.begin(), myvector.end());
		std::vector<int>::iterator it_prec = myvector.begin();
		for (std::vector<int>::iterator it = myvector.begin() + 1; it < myvector.end(); it++) {
			if (*it - *it_prec < span)
				span = *it - *it_prec;
			it_prec = it;
		}
		return (span);
	}
	catch (std::exception & e) { 
		throw ; 
	};
}

int Span::longestSpan() const {
	if (this->_nb_elem < 2)
		throw(NoSpanPossibleException());
	return (*std::max_element(this->_span.begin(), this->_span.end()) - *std::min_element(this->_span.begin(), this->_span.end()));
}
