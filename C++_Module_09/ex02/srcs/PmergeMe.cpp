/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/06/05 16:39:29 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) : _parity(0) {
	try {
		this->_my_vect.reserve(ac - 1);
		for (int i = 1; i < ac; i++)
			this->_my_vect.push_back(atoi(av[i])); // check si atoi overflow
		std::cout << "End constructor" << std::endl;
	}
	catch (std::bad_alloc & e) {
		throw ;
	}
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

size_t	PmergeMe::make_pair(std::pair<int, int> * pair) {
	
	int i = 0;
	
	for (std::vector<int>::iterator it = this->_my_vect.begin(); it != this->_my_vect.end(); it+=2) {
		if (it + 1 == this->_my_vect.end())
		{
			this->_left = *it;
			this->_parity = 1;
			break;
		}
		if (*it >= *(it + 1))
		{
			pair[i].first = *it;
			pair[i].second = *(it + 1);
		}
		else
		{
			pair[i].first = *(it + 1);
			pair[i].second = *it;
		}
		i++;
	}
	return (i);
}

std::pair<int, int> *	PmergeMe::rec_sort_hight_elem(std::pair<int, int> * pair, int begin, int end) {
	
	if (begin == end )
	{
		std::pair<int, int> * sorted = new std::pair<int, int>[sizeof(std::pair<int, int>)];
		sorted[0] = pair[begin];
		return sorted;
	}
	std::pair<int, int> * arr_1 = rec_sort_hight_elem(pair, begin, begin + (end - begin) / 2);
	std::pair<int, int> * arr_2 = rec_sort_hight_elem(pair, begin + (end - begin) / 2 + 1, end);
	std::pair<int, int> * sorted = new std::pair<int, int>[sizeof(std::pair<int, int>) * end - begin + 1];
	std::merge(arr_1, arr_1 + (begin + (end - begin) / 2) - begin + 1, arr_2, arr_2 + end - begin - (end - begin) / 2, sorted);
	delete[] arr_1;
	delete[] arr_2;
	return (sorted);
}

/* ************************************************************************* */
/* ******************************** Vector  ******************************** */
/* ************************************************************************* */

void	PmergeMe::dichotomic_insertion(std::vector<int> & sorted, std::pair<int,int> * pair, size_t size) {
	
	size_t i = 1; // a incrementer quand on insere un nb
	std::vector<int>::iterator it;
	size_t j_next /* = jacobsthal_suit(1) */; //=> on recherche entre index 0 et index j + i
	size_t j = 1;
	
	while (1)
	{
		j_next = jacobsthal_suit(1);
		if (j_next >= size)
			j_next = size;
		if (j == j_next)
			break;
		it = std::upper_bound(sorted.begin(), sorted.begin() + j_next + i, pair[j_next - 1].second);
		sorted.insert(it, pair[j_next - 1].second);
		i++;
		j++;
		while (j < j_next) {
			it = std::upper_bound(sorted.begin(), sorted.begin() + j + i, pair[j - 1].second);
			sorted.insert(it, pair[j - 1].second);
			i++;
			j++;
		}
		if (j_next == size)
			break;
	}
}

void	PmergeMe::to_vector() {
	
	std::pair<int, int> *pair;
	size_t				size;
	
	/* Create array of pair with elements' pair sorted */
	try {
		std::cout << "this->_my_vect.size() / 2 = " << this->_my_vect.size() / 2 << std::endl;
		pair = new std::pair<int, int>[this->_my_vect.size() / 2];
		size = make_pair(pair);
	}
	catch(std::bad_alloc & e) { throw; }
	
	/* Check */
	// for (size_t i = 0; i < size; i++)
	// 	std::cout << pair[i].first << " et " << pair[i].second << std::endl;
		
	/* Sort pair regards to highest elements */
	std::pair<int , int> * sorted_pair = rec_sort_hight_elem(pair, 0, size - 1);
	
	/* Check */
	// for (size_t i = 0; i < size; i++)
	// 	std::cout << sorted_pair[i].first << " et " << sorted_pair[i].second << std::endl;
	// delete[] pair;
	
	std::vector<int> sorted;
	sorted.reserve(this->_my_vect.size());

	/* Push highest elements sorted to vector */
	for (size_t i = 0; i < size; i++)
		sorted.push_back(sorted_pair[i].first);
	
	/* Check */
	// std::cout << "*************************" << std::endl;
	// for(std::vector<int>::iterator kt = sorted.begin(); kt != sorted.end(); kt++)
	// 	std::cout << *kt << std::endl;
	
	/* Insert the smallest element of thefirst pair */
	sorted.insert(sorted.begin(), sorted_pair[0].second);
	
	/* Check */
	// std::cout << "*************************" << std::endl;
	// for(std::vector<int>::iterator kt = sorted.begin(); kt != sorted.end(); kt++)
	// 	std::cout << *kt << std::endl;
	
	/* Insert the smallest elems of pair */
	this->dichotomic_insertion(sorted, sorted_pair, size);
	delete [] sorted_pair;
	
	if (this->_parity == 1)
	{
		std::vector< int >::iterator itt = std::upper_bound(sorted.begin(), sorted.end(), this->_left);
		sorted.insert(itt, this->_left);
	}
	std::cout.fill(' ');
	std::cout.flags(std::ios::left);
	std::cout.width(10);
	std::cout << "After :";
	std::cout.width();
	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/* ************************************************************************* */
/* ******************************** Deque  ********************************* */
/* ************************************************************************* */

void	PmergeMe::dichotomic_insertion(std::deque<int> & sorted, std::pair<int,int> * pair, size_t size) {
	
	size_t i = 1; // a incrementer quand on insere un nb
	std::deque<int>::iterator it;
	size_t j_next /* = jacobsthal_suit(1) */; //=> on recherche entre index 0 et index j + i
	size_t j = 1;
	
	while (1)
	{
		j_next = jacobsthal_suit(1);
		if (j_next >= size)
			j_next = size;
		if (j == j_next)
			break;
		it = std::upper_bound(sorted.begin(), sorted.begin() + j_next + i, pair[j_next - 1].second);
		sorted.insert(it, pair[j_next - 1].second);
		i++;
		j++;
		while (j < j_next) {
			it = std::upper_bound(sorted.begin(), sorted.begin() + j + i, pair[j - 1].second);
			sorted.insert(it, pair[j - 1].second);
			i++;
			j++;
		}
		if (j_next == size)
			break;
	}
}

void	PmergeMe::to_deque() {
	
	std::pair<int, int> *pair;
	size_t				size;
	
	/* Create array of pair with elements' pair sorted */
	try {
		std::cout << "this->_my_vect.size() / 2 = " << this->_my_vect.size() / 2 << std::endl;
		pair = new std::pair<int, int>[this->_my_vect.size() / 2];
		size = make_pair(pair);
	}
	catch(std::bad_alloc & e) { throw; }
	
	/* Check */
	// for (size_t i = 0; i < size; i++)
	// 	std::cout << pair[i].first << " et " << pair[i].second << std::endl;
		
	/* Sort pair regards to highest elements */
	std::pair<int , int> * sorted_pair = rec_sort_hight_elem(pair, 0, size - 1);
	
	/* Check */
	// for (size_t i = 0; i < size; i++)
	// 	std::cout << sorted_pair[i].first << " et " << sorted_pair[i].second << std::endl;
	// delete[] pair;
	
	std::deque<int> sorted;
	// sorted.reserve(this->_my_vect.size());

	/* Push highest elements sorted to deque */
	for (size_t i = 0; i < size; i++)
		sorted.push_back(sorted_pair[i].first);
	
	/* Check */
	// std::cout << "*************************" << std::endl;
	// for(std::deque<int>::iterator kt = sorted.begin(); kt != sorted.end(); kt++)
	// 	std::cout << *kt << std::endl;
	
	/* Insert the smallest element of thefirst pair */
	sorted.insert(sorted.begin(), sorted_pair[0].second);
	
	/* Check */
	// std::cout << "*************************" << std::endl;
	// for(std::deque<int>::iterator kt = sorted.begin(); kt != sorted.end(); kt++)
	// 	std::cout << *kt << std::endl;
	
	/* Insert the smallest elems of pair */
	this->dichotomic_insertion(sorted, sorted_pair, size);
	delete [] sorted_pair;
	
	if (this->_parity == 1)
	{
		std::deque< int >::iterator itt = std::upper_bound(sorted.begin(), sorted.end(), this->_left);
		sorted.insert(itt, this->_left);
	}
	std::cout.fill(' ');
	std::cout.flags(std::ios::left);
	std::cout.width(10);
	std::cout << "After :";
	std::cout.width();
	for (std::deque<int>::iterator it = sorted.begin(); it != sorted.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// void	PmergeMe::swap_elem(std::deque< std::pair<int, int> >::iterator & elem1, std::deque< std::pair<int, int> >::iterator & elem2) {
	
// 	std::pair<int, int> tmp;
	
// 	tmp = *elem1;
// 	*elem1 = *elem2;
// 	*elem2 = tmp;
// }

// void	PmergeMe::rec_sort_hight_elem(std::deque< std::pair<int, int> > & d_p, std::deque< std::pair<int, int> >::iterator & curr) {
// 	if (curr == d_p.end())
// 		return ;
// 	else {
// 		std::deque< std::pair<int, int> >::iterator it = curr++;
// 		if (curr != d_p.end() && (*it).first > (*curr).first) {
// 			swap_elem(it, curr);
// 			it = d_p.begin();
// 			rec_sort_hight_elem(d_p, it);
// 		}
// 		it++;
// 		rec_sort_hight_elem(d_p, it);
// 	}
// }

// void	PmergeMe::dichotomic_insertion(std::deque< std::pair<int,int> > & d_p) {
	
// 	size_t i = 1; // a incrementer quand on insere un nb
// 	std::deque<int>::iterator it;
// 	size_t j_next; //=> on recherche entre index 0 et index j + i
// 	size_t j = 1;
	
// 	while (1)
// 	{
// 		j_next = jacobsthal_suit(1);
// 		if (j_next >= d_p.size())
// 			j_next = d_p.size();
// 		it = std::upper_bound(this->_my_deque.begin(), this->_my_deque.begin() + j_next + i, d_p[j_next - 1].second);
// 		this->_my_deque.insert(it, d_p[j_next - 1].second);
// 		i++;
// 		j++;
// 		while (j < j_next) {
// 			it = std::upper_bound(this->_my_deque.begin(), this->_my_deque.begin() + j + i, d_p[j - 1].second);
// 			this->_my_deque.insert(it, d_p[j - 1].second);
// 			i++;
// 			j++;
// 		}
// 		if (j_next == d_p.size())
// 			break;
// 	}
// }

// void	PmergeMe::to_deque() {
	
// 	std::istringstream iss(this->_suit); // voir si besoin protection si string null
// 	std::deque< std::pair<int,int> >	d_p;
// 	std::pair<int, int> p;
	
// 	iss.exceptions(std::istream::failbit);
// 	/* Create deque of pair with elements' pair sorted */
// 	while (1)
// 	{
// 		try {
// 			make_sort_pair(iss, p);
// 		}
// 		catch(std::istream::failure & e) { break; }
// 		d_p.push_back(p);
// 	}

// 	/* Insert in deque the highest elements of pair sorted in recursive */
// 	std::deque< std::pair<int, int> >::iterator begin = d_p.begin();
// 	rec_sort_hight_elem(d_p, begin);
// 	for (std::deque< std::pair<int, int> >::iterator it = d_p.begin(); it < d_p.end(); it++)
// 		this->_my_deque.push_back((*it).first);
	
// 	/* Insert the smallest element of thefirst pair */
// 	this->_my_deque.insert(this->_my_deque.begin(), d_p[0].second);
	
// 	/* Insert the smallest elems of pair */
// 	this->dichotomic_insertion(d_p);
	
// 	if (this->_parity == 1)
// 	{
// 		std::deque< int >::iterator itt = std::upper_bound(this->_my_deque.begin(), this->_my_deque.end(), this->_left);
// 		this->_my_deque.insert(itt, this->_left);
// 	}
// 	std::cout.fill(' ');
// 	std::cout.flags(std::ios::left);
// 	std::cout.width(10);
// 	std::cout << "After :";
// 	std::cout.width();
// 	for (std::deque<int>::iterator it = _my_deque.begin(); it != _my_deque.end(); it++)
// 		std::cout << *it << " ";
// }
