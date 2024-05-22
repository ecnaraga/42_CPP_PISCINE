/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/05/22 16:51:26 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string & s) : _suit(s) , _parity(0) {
}

PmergeMe::PmergeMe(PmergeMe & orig) {
	*this = orig;
}

PmergeMe::~PmergeMe() {}



/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

PmergeMe & PmergeMe::operator=(PmergeMe & rhs) {
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

void	PmergeMe::to_vector() {
	
	std::istringstream iss(this->_suit); // voir si besoin protection si string null
	std::pair<int, int> p;
	int nb1, nb2;
	
	iss.exceptions(std::istream::failbit);
	while (1)
	{
		try {
			iss >> nb1;
		}
		catch(std::istream::failure & e) { break; }
		try {
			iss >> nb2;
		}
		catch(std::istream::failure & e) {
			this->_parity = 1;
			this->_left = nb1;
			break; }
		if (nb1 >= nb2)
		{
			p.first = nb1;
			p.second = nb2;
		}
		else
		{
			p.first = nb2;
			p.second = nb1;
		}
		this->_my_vect.push_back(p);
	}
	for (std::vector< std::pair<int, int> >::iterator it = _my_vect.begin(); it < _my_vect.end(); it++) {
		std::cout << static_cast< std::pair < int, int > > (*it).first << std::endl;
		std::cout << static_cast< std::pair < int, int > > (*it).second << std::endl << std::endl;
	}
}