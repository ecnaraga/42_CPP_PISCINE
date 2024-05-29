/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/05/26 09:12:59 by garance          ###   ########.fr       */
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

unsigned long long int	PmergeMe::jacobsthal_suit() const {
	static unsigned long long int n_m1 = 1;
	static unsigned long long int n_curr = 1;
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
	else // if (n_curr == 1)
		n_curr = 3;
	i++;
	return (n_curr);
}

/* void	PmergeMe::swap_elem(std::vector< std::pair<int, int> >::iterator & elem1, std::vector< std::pair<int, int> >::iterator & elem2) {
	
	elem1 = elem2; // verifier si ca swap ou non
	// static_cast< std::pair <int, int> >(*elem1).first = static_cast< std::pair <int, int> > (*elem2).first;
	// static_cast< std::pair <int, int> >(*elem1).second = static_cast< std::pair <int, int> > (*elem2).second;
	
}

void	PmergeMe::rec_sort_hight_elem(std::vector< std::pair<int, int> >::iterator & curr) {
	if (curr == this->_my_vect.end())
		return ;
	else {
		std::vector< std::pair<int, int> >::iterator it = curr++;
		if (static_cast< std::pair<int, int> > (*it).first < static_cast< std::pair<int, int> > (*curr).first) {
			swap_elem(it, curr);
			this->_my_vect[it];
			rec_sort_hight_elem(this->_my_vect.begin());
		}
	}
}

void	PmergeMe::sort_pair(std::pair<int, int> * p) {
	
	int j = 0;
	
	for (std::vector<int>::iterator it = _my_vect.begin(); it != this->_my_vect.end(); it++) {
		if (it + 1 == this->_my_vect.end()) {
			this->_left = *it;
			break ;
		}
		if (*it >= *(it + 1))
		{
			p[j].first = *it;
			p[j].second = *(it + 1);
		}
		else
		{
			p[j].first = *(it + 1);
			p[j].second = *it;
		}
		j += 1;
	}
}

void	PmergeMe::to_vector() {
	
	std::istringstream iss(this->_suit); // voir si besoin protection si string null
	// std::pair<int, int> p;
	int nb;
	
	iss.exceptions(std::istream::failbit);
	while (1)
	{
		try {
			iss >> nb;
		}
		catch(std::istream::failure & e) { break; }
		this->_my_vect.push_back(nb);
	}
	std::pair<int, int> *p = new std::pair<int, int>[this->_my_vect.size() / 2]; //proteger alloc dynamic cf nothrow avec new
	sort_pair(p);
	rec_sort_hight_elem(this->_my_vect.begin());
} */

void	PmergeMe::swap_elem(std::vector< std::pair<int, int> >::iterator & elem1, std::vector< std::pair<int, int> >::iterator & elem2) {
	
	std::pair<int, int> tmp;
	
	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void	PmergeMe::rec_sort_hight_elem(std::vector< std::pair<int, int> > & v_p, std::vector< std::pair<int, int> >::iterator & curr) {
	if (curr == v_p.end())
		return ;
	else {
		std::vector< std::pair<int, int> >::iterator it = curr++;
		if (curr != v_p.end() && static_cast< std::pair<int, int> > (*it).first > static_cast< std::pair<int, int> > (*curr).first) {
			swap_elem(it, curr);
			it = v_p.begin();
			rec_sort_hight_elem(v_p, it);
		}
		it++;
		rec_sort_hight_elem(v_p, it);
	}
}


void	PmergeMe::to_vector() {
	
	std::istringstream iss(this->_suit); // voir si besoin protection si string null
	std::vector< std::pair<int,int> >	v_p;
	std::pair<int, int> p;
	int nb1, nb2;
	
	iss.exceptions(std::istream::failbit);
	/* Create vector of pair with elements' pair sorted */
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
		v_p.push_back(p);
	}
	/* Check */
	for (std::vector< std::pair<int, int> >::iterator it = v_p.begin(); it < v_p.end(); it++) {
		std::cout << static_cast< std::pair < int, int > > (*it).first << std::endl;
		std::cout << static_cast< std::pair < int, int > > (*it).second << std::endl << std::endl;
	}

	/* Insert in vector the highest elements of pair sorted in recursive */
	std::vector< std::pair<int, int> >::iterator it = v_p.begin();
	rec_sort_hight_elem(v_p, it);
	std::cout << "*********************" << std::endl;
	for (std::vector< std::pair<int, int> >::iterator it = v_p.begin(); it < v_p.end(); it++) {
		std::cout << static_cast< std::pair < int, int > > (*it).first << std::endl;
		std::cout << static_cast< std::pair < int, int > > (*it).second << std::endl << std::endl;
		this->_my_vect.push_back((*it).first);
	}
	std::cout << "*********************" << std::endl;
	
	/* Insert the smallest element of thefirst pair */
	this->_my_vect.insert(this->_my_vect.begin(), v_p[0].second);
	for (std::vector<int>::iterator it = _my_vect.begin(); it != _my_vect.end(); it++)
		std::cout << *it << std::endl;
	
	/* Insert the smallest elems of pair */
	// int i = 0;
	// while (1)
	// {
	// 	int j = jacobsthal_suit();
	// }
}