/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/06/03 16:31:55 by galambey         ###   ########.fr       */
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

/* ************************************************************************* */
/* ***************************** Vector + deque **************************** */
/* ************************************************************************* */

size_t	PmergeMe::jacobsthal_suit(int order) const {
	static unsigned long long int n_m1 = 1;
	static unsigned long long int n_curr = 1;
	static short int i = 0;
	int tmp;
	
	if (order == 0)
	{
		n_m1 = 1;
		n_curr = 1;
		i = 0;
	}
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

void	PmergeMe::swap_elem(std::vector< std::pair<int, int> >::iterator * elem1, std::vector< std::pair<int, int> >::iterator * elem2) {
	
	std::pair<int, int> tmp;
	
	tmp = **elem1;
	**elem1 = **elem2;
	**elem2 = tmp;
}

void	PmergeMe::make_sort_pair(std::istringstream & iss, std::pair<int, int> & p) {
	
	int nb1, nb2;
	
	std::cout << "begin make_sor_pair" << std::endl;
	try {
		iss >> nb1;
	}
	catch(std::istream::failure & e) { throw; }
	try {
		iss >> nb2;
	}
	catch(std::istream::failure & e) {
		this->_parity = 1;
		this->_left = nb1;
		throw; }
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
	std::cout << "end make_sor_pair" << std::endl;
}

/* ************************************************************************* */
/* ******************************** Vector  ******************************** */
/* ************************************************************************* */

void	PmergeMe::rec_sort_hight_elem(std::vector< std::pair<int, int> > & v_p, std::vector< std::pair<int, int> >::iterator curr) {
	// static int i = 0; // a effacer
	
	// std::cout << "entree recursive i = " << i << std::endl;
	// i++;
	if (curr == v_p.end())
		return ;
	else {
		// std::vector< std::pair<int, int> >::iterator next = curr++;
		if (curr != v_p.end() && (*(curr + 1)).first > (*curr).first) {
			void *c = &(curr);
			swap_elem(c, &curr);
			// next = v_p.begin();
			// std::cout << "rappel recursive depuis begin()" << std::endl;
			rec_sort_hight_elem(v_p, v_p.begin());
			// rec_sort_hight_elem(v_p, next);
		}
		// std::cout << "test0 : " << (*next).first << std::endl;
		else
		{
		curr++;
		// std::cout << "test00 : " << (*next).first << std::endl;
		// std::cout << "test1" << std::endl;
		if (curr == v_p.end())
			return ;
		// std::cout << "test2" << std::endl;
		rec_sort_hight_elem(v_p, curr);
		}
	}
}

void	PmergeMe::dichotomic_insertion(std::vector< std::pair<int,int> > & v_p) {
	
	size_t i = 1; // a incrementer quand on insere un nb
	std::vector<int>::iterator it;
	size_t j_next /* = jacobsthal_suit(1) */; //=> on recherche entre index 0 et index j + i
	size_t j = 1;
	
	std::cout << "begin dichotomic" << std::endl;
	while (1)
	{
		j_next = jacobsthal_suit(1);
		if (j_next >= v_p.size())
			j_next = v_p.size();
		if (j == j_next)
			break;
		it = std::upper_bound(this->_my_vect.begin(), this->_my_vect.begin() + j_next + i, v_p[j_next - 1].second);
		this->_my_vect.insert(it, v_p[j_next - 1].second);
		i++;
		j++;
		while (j < j_next) {
			it = std::upper_bound(this->_my_vect.begin(), this->_my_vect.begin() + j + i, v_p[j - 1].second);
			this->_my_vect.insert(it, v_p[j - 1].second);
			i++;
			j++;
		}
		if (j_next == v_p.size())
			break;
	}
	std::cout << "end dichotomic" << std::endl;
}

void	PmergeMe::to_vector() {
	
	std::istringstream iss(this->_suit); // voir si besoin protection si string null
	std::vector< std::pair<int,int> >	v_p;
	std::pair<int, int> p;
	
	iss.exceptions(std::istream::failbit);
	/* Create vector of pair with elements' pair sorted */
	while (1)
	{
		try {
			make_sort_pair(iss, p);
		}
		catch(std::istream::failure & e) { break; }
		v_p.push_back(p);
	}
	for (std::vector< std::pair < int, int > >::iterator kt = v_p.begin(); kt != v_p.end(); kt++) {
		std::cout << (*kt).first << " et " << (*kt).second << std::endl;
	}
	/* Insert in vector the highest elements of pair sorted in recursive */
	std::vector< std::pair<int, int> >::iterator it = v_p.begin();
	std::cout << "begin recursive" << std::endl;
	rec_sort_hight_elem(v_p, it);
	std::cout << "end recursive" << std::endl;
	for (std::vector< std::pair<int, int> >::iterator it = v_p.begin(); it < v_p.end(); it++)
		this->_my_vect.push_back((*it).first);
	for(std::vector<int>::iterator kt = this->_my_vect.begin(); kt != this->_my_vect.end(); kt++)
		std::cout << *kt << std::endl;

	// int i = 1;
	// for (std::vector< std::pair<int, int> >::iterator it = v_p.begin(); it < v_p.end(); it++) {
	// 	std::cout << "index : " << i << " => " << (*it).first << " " << (*it).second << std::endl;
	// 	i++;
	// }
	
	/* Insert the smallest element of thefirst pair */
	this->_my_vect.insert(this->_my_vect.begin(), v_p[0].second);
	for(std::vector<int>::iterator kt = this->_my_vect.begin(); kt != this->_my_vect.end(); kt++)
		std::cout << *kt << std::endl;
	/* Insert the smallest elems of pair */
	this->dichotomic_insertion(v_p);
	
	if (this->_parity == 1)
	{
		std::vector< int >::iterator itt = std::upper_bound(this->_my_vect.begin(), this->_my_vect.end(), this->_left);
		this->_my_vect.insert(itt, this->_left);
	}
	std::cout.fill(' ');
	std::cout.flags(std::ios::left);
	std::cout.width(10);
	std::cout << "After :";
	std::cout.width();
	for (std::vector<int>::iterator it = _my_vect.begin(); it != _my_vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/* ************************************************************************* */
/* ******************************** Deque  ********************************* */
/* ************************************************************************* */

void	PmergeMe::swap_elem(std::deque< std::pair<int, int> >::iterator & elem1, std::deque< std::pair<int, int> >::iterator & elem2) {
	
	std::pair<int, int> tmp;
	
	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void	PmergeMe::rec_sort_hight_elem(std::deque< std::pair<int, int> > & d_p, std::deque< std::pair<int, int> >::iterator & curr) {
	if (curr == d_p.end())
		return ;
	else {
		std::deque< std::pair<int, int> >::iterator it = curr++;
		if (curr != d_p.end() && (*it).first > (*curr).first) {
			swap_elem(it, curr);
			it = d_p.begin();
			rec_sort_hight_elem(d_p, it);
		}
		it++;
		rec_sort_hight_elem(d_p, it);
	}
}

void	PmergeMe::dichotomic_insertion(std::deque< std::pair<int,int> > & d_p) {
	
	size_t i = 1; // a incrementer quand on insere un nb
	std::deque<int>::iterator it;
	size_t j_next; //=> on recherche entre index 0 et index j + i
	size_t j = 1;
	
	while (1)
	{
		j_next = jacobsthal_suit(1);
		if (j_next >= d_p.size())
			j_next = d_p.size();
		it = std::upper_bound(this->_my_deque.begin(), this->_my_deque.begin() + j_next + i, d_p[j_next - 1].second);
		this->_my_deque.insert(it, d_p[j_next - 1].second);
		i++;
		j++;
		while (j < j_next) {
			it = std::upper_bound(this->_my_deque.begin(), this->_my_deque.begin() + j + i, d_p[j - 1].second);
			this->_my_deque.insert(it, d_p[j - 1].second);
			i++;
			j++;
		}
		if (j_next == d_p.size())
			break;
	}
}

void	PmergeMe::to_deque() {
	
	std::istringstream iss(this->_suit); // voir si besoin protection si string null
	std::deque< std::pair<int,int> >	d_p;
	std::pair<int, int> p;
	
	iss.exceptions(std::istream::failbit);
	/* Create deque of pair with elements' pair sorted */
	while (1)
	{
		try {
			make_sort_pair(iss, p);
		}
		catch(std::istream::failure & e) { break; }
		d_p.push_back(p);
	}

	/* Insert in deque the highest elements of pair sorted in recursive */
	std::deque< std::pair<int, int> >::iterator begin = d_p.begin();
	rec_sort_hight_elem(d_p, begin);
	for (std::deque< std::pair<int, int> >::iterator it = d_p.begin(); it < d_p.end(); it++)
		this->_my_deque.push_back((*it).first);
	
	/* Insert the smallest element of thefirst pair */
	this->_my_deque.insert(this->_my_deque.begin(), d_p[0].second);
	
	/* Insert the smallest elems of pair */
	this->dichotomic_insertion(d_p);
	
	if (this->_parity == 1)
	{
		std::deque< int >::iterator itt = std::upper_bound(this->_my_deque.begin(), this->_my_deque.end(), this->_left);
		this->_my_deque.insert(itt, this->_left);
	}
	std::cout.fill(' ');
	std::cout.flags(std::ios::left);
	std::cout.width(10);
	std::cout << "After :";
	std::cout.width();
	for (std::deque<int>::iterator it = _my_deque.begin(); it != _my_deque.end(); it++)
		std::cout << *it << " ";
}
