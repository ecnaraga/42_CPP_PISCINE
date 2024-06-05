/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/05/29 19:21:55 by galambey         ###   ########.fr       */
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

// unsigned long long int	PmergeMe::jacobsthal_suit() const {
// 	static unsigned long long int n_m1 = 1;
// 	static unsigned long long int n_curr = 1;
// 	static short int i = 0;
// 	int tmp;
	
// 	if (i > 31)
// 		throw (OverflowException());
// 	if (n_curr > 1)
// 	{
// 		tmp = n_curr;
// 		n_curr = n_m1 * 2 + n_curr;
// 		n_m1 = tmp;
// 	}
// 	else // if (n_curr == 1)
// 		n_curr = 3;
// 	i++;
// 	return (n_curr);
// }

size_t	PmergeMe::jacobsthal_suit() const {
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

void	PmergeMe::dichotomic_insertion(std::vector< std::pair<int,int> > & v_p) {
	
	size_t i = 1; // a incrementer quand on insere un nb
	size_t j = jacobsthal_suit(); //=> on recherche entre index 0 et index j + i
	size_t j_next;
	std::vector<int>::iterator it;
	while (1)
	{
		it = std::upper_bound(this->_my_vect.begin(), this->_my_vect.begin() + j + i, v_p[j - 1].second);
		this->_my_vect.insert(it, v_p[j - 1].second);
		i++;
		j++;
		j_next = jacobsthal_suit();
		if (j_next >= v_p.size())
			j_next = v_p.size();
		while (j <= j_next) {
			it = std::upper_bound(this->_my_vect.begin(), this->_my_vect.begin() + j + i, v_p[j - 1].second);
			this->_my_vect.insert(it, v_p[j - 1].second);
			i++;
			j++;
		}
		if (j_next == v_p.size())
			break;
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

	/* Insert in vector the highest elements of pair sorted in recursive */
	std::vector< std::pair<int, int> >::iterator it = v_p.begin();
	rec_sort_hight_elem(v_p, it);
	for (std::vector< std::pair<int, int> >::iterator it = v_p.begin(); it < v_p.end(); it++)
		this->_my_vect.push_back((*it).first);
	
	/* Insert the smallest element of thefirst pair */
	this->_my_vect.insert(this->_my_vect.begin(), v_p[0].second);
	
	/* Insert the smallest elems of pair */
	this->dichotomic_insertion(v_p);
	
	if (this->_parity == 1)
	{
		std::vector< int >::iterator itt = std::upper_bound(this->_my_vect.begin(), this->_my_vect.end(), this->_left);
		this->_my_vect.insert(itt, this->_left);
	}
	for (std::vector<int>::iterator it = _my_vect.begin(); it != _my_vect.end(); it++)
		std::cout << *it << std::endl;
}