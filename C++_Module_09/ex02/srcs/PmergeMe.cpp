/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/05/15 16:26:08 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string & s) : _suit(s) {
}

PmergeMe::PmergeMe(PmergeMe & orig) {
	(void) orig;
}

PmergeMe::~PmergeMe() {}

PmergeMe::Pair::Pair() {}

PmergeMe::Pair::Pair(PmergeMe::Pair & orig) {
	(void) orig;
}

PmergeMe::Pair::Pair(int n1, int n2) {
	if (n1 > n2) {
		this->_large = n1;
		this->_small = n2;
	}
	else {
		this->_large = n2;
		this->_small = n1;
	}
}

PmergeMe::Pair::~Pair() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

PmergeMe & PmergeMe::operator=(PmergeMe & rhs) {
	(void) rhs;
	return (*this);
}

PmergeMe::Pair & PmergeMe::Pair::operator=(PmergeMe::Pair & rhs) {
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char *	PmergeMe::OverflowException::what() const throw() {
	return ("overflow");
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

unsigned long long int	PmergeMe::jacobsthal_suit() /* const  */{
	static unsigned long long int n_m1 = 1;
	static unsigned long long int n_curr = 0;
	static short int i = 0;
	int tmp;
	
	if (i > 31)
		throw (OverflowException());
	if (n_curr > 1)
	{
		tmp = n_curr;
		n_curr = n_m1 * 2 + n_curr;
		n_m1 = tmp;
	}
	else if (n_curr == 0)
	{
		n_curr = 1;
	}
	else // if (n_curr == 1)
	{
		n_curr = 3;
	}
	i++;
	return (n_curr);
}
