/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:53 by galambey          #+#    #+#             */
/*   Updated: 2024/06/06 18:12:39 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) : _parity(0), _ac(ac), _av(av) {}

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

PmergeMe::PmergeMeException::PmergeMeException(const char *err) : _err(err) {}

const char *	PmergeMe::PmergeMeException::what() const throw() {
	return (_err);
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
		throw (PmergeMeException("Error : jacobsthal_suit : overflow"));
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



/* ************************************************************************* */
/* ******************************** Vector  ******************************** */
/* ************************************************************************* */

void	PmergeMe::parse_nb(std::vector<int> & to_sort) const {
	
	int nb;
	int j;
	
	for (int i = 1; i < this->_ac; i++)
	{
		for (j = 0; _av[i][j]; j++)
		{
			if (!isdigit(_av[i][j]))
				throw (PmergeMeException("Error"));
		}
		nb = atoi(this->_av[i]);
		if (nb < 0)
			throw (PmergeMeException("Error"));
		to_sort.push_back(nb);
	}
}

void	PmergeMe::make_pair(std::vector<std::pair<int, int> > & pair, std::vector<int> & to_sort) {
	
	std::vector<std::pair<int, int> >::iterator iv = pair.begin();
	
	for (std::vector<int>::iterator it = to_sort.begin(); it != to_sort.end(); it += 2) {
		if (it + 1 == to_sort.end())
		{
			this->_left = *it;
			this->_parity = 1;
			break;
		}
		if (*it >= *(it + 1))
		{
			(*iv).first = *it;
			(*iv).second = *(it + 1);
		}
		else
		{
			(*iv).first = *(it + 1);
			(*iv).second = *it;
		}
		iv++;
	}
}

std::vector<std::pair<int, int> > *	PmergeMe::rec_sort_hight_elem(std::vector<std::pair<int, int> > & pair, int begin, int end) {
	
	if (begin == end )
	{
		std::vector<std::pair<int, int> > * sorted = new std::vector<std::pair<int, int> >;
		(*sorted).push_back(pair[begin]);
		return sorted;
	}
	std::vector<std::pair<int, int> > *arr_1 = NULL, *arr_2 = NULL, *sorted = NULL;
	try {
		arr_1 = rec_sort_hight_elem(pair, begin, begin + (end - begin) / 2);
		arr_2 = rec_sort_hight_elem(pair, begin + (end - begin) / 2 + 1, end);
		sorted = new std::vector<std::pair<int, int> >((*arr_1).size() + (*arr_2).size()) ;
		std::merge((*arr_1).begin(), (*arr_1).end(), (*arr_2).begin(), (*arr_2).end(), (*sorted).begin());
		delete arr_1;
		delete arr_2;
		return (sorted);
	}
	catch (std::bad_alloc const & e) {
		delete arr_1;
		delete arr_2;
		delete sorted;
		throw ;
	}
}

void	PmergeMe::dichotomic_insertion(std::vector<int> & sorted, std::vector< std::pair<int, int> > * pair, size_t size) {
	
	size_t i = 1;
	std::vector<int>::iterator it;
	size_t j_next;
	size_t j = 1;
	
	while (1)
	{
		j_next = jacobsthal_suit(1);
		if (j_next >= size)
			j_next = size;
		if (j == j_next)
			break;
		it = std::upper_bound(sorted.begin(), sorted.begin() + j_next + i, (*pair)[j_next - 1].second);
		sorted.insert(it, (*pair)[j_next - 1].second);
		i++;
		j++;
		while (j < j_next) {
			it = std::upper_bound(sorted.begin(), sorted.begin() + j + i, (*pair)[j - 1].second);
			sorted.insert(it, (*pair)[j - 1].second);
			i++;
			j++;
		}
		if (j_next == size)
			break;
	}
}

void	PmergeMe::to_vector() {
	
	std::vector<std::pair<int, int> > pair;
	std::vector< int > to_sort;
	size_t				size;
	std::vector<std::pair<int, int> > * sorted_pair = NULL;
	
	try { // necessaire car allocation dynamique pour delete
		to_sort.reserve(this->_ac - 1);
		parse_nb(to_sort);
		print_container< std::vector<int> >(to_sort, "Before :");
		
		/* Create array of pair with elements' pair sorted */
		size = to_sort.size() / 2;
		// std::cout << "to_sort.size() = " << to_sort.size() << std::endl;
		pair.reserve(sizeof(std::pair<int, int>) * size);
		make_pair(pair, to_sort);
		
		/* Sort pair regards to highest elements */
		sorted_pair = rec_sort_hight_elem(pair, 0, size - 1);
		
		/* Push highest elements sorted to vector */
		std::vector<int> sorted;
		sorted.reserve(to_sort.size());
		for (std::vector< std::pair<int, int> >::iterator it = (*sorted_pair).begin(); it != (*sorted_pair).end(); it++)
			sorted.push_back((*it).first);
		
		/* Insert the smallest element of thefirst pair */
		sorted.insert(sorted.begin(), (*(*sorted_pair).begin()).second);
		
		// /* Insert the smallest elems of pair */
		this->dichotomic_insertion(sorted, sorted_pair, size);
		delete sorted_pair;
		sorted_pair = NULL;
		
		if (this->_parity == 1)
		{
			std::vector< int >::iterator itt = std::upper_bound(sorted.begin(), sorted.end(), this->_left);
			sorted.insert(itt, this->_left);
		}
		print_container< std::vector<int> >(sorted, "After :");
		// std::cout << "to_sort.size() = " << sorted.size() << std::endl;
	}
	catch (std::bad_alloc const & e) {
		delete sorted_pair;
		throw ; }
	catch (std::out_of_range const & e) {
		delete sorted_pair;
		throw ; }
	catch (std::length_error const & e) {
		delete sorted_pair;
		throw ; }
	catch (std::exception const & e) {
		delete sorted_pair;
		throw ; }
}

/* ************************************************************************* */
/* ******************************** Deque  ********************************* */
/* ************************************************************************* */

void	PmergeMe::parse_nb(std::deque<int> & to_sort) const {
	
	int nb;
	int j;
	
	for (int i = 1; i < this->_ac; i++)
	{
		for (j = 0; _av[i][j]; j++)
		{
			if (!isdigit(_av[i][j]))
				throw (PmergeMeException("Error"));
		}
		nb = atoi(this->_av[i]);
		if (nb < 0)
			throw (PmergeMeException("Error"));
		to_sort.push_back(nb);
	}
}

void	PmergeMe::make_pair(std::deque<std::pair<int, int> > & pair, std::deque<int> & to_sort) {
	
	std::deque<std::pair<int, int> >::iterator iv = pair.begin();
	for (std::deque<int>::iterator it = to_sort.begin(); it != to_sort.end(); it+=2) {
		if (it + 1 == to_sort.end())
		{
			this->_left = *it;
			this->_parity = 1;
			break;
		}
		if (*it >= *(it + 1))
		{
			(*iv).first = *it;
			(*iv).second = *(it + 1);
		}
		else
		{
			(*iv).first = *(it + 1);
			(*iv).second = *it;
		}
		iv++;
	}
}

std::deque<std::pair<int, int> > *	PmergeMe::rec_sort_hight_elem(std::deque<std::pair<int, int> > & pair, int begin, int end) {
	
	if (begin == end )
	{
		std::deque<std::pair<int, int> > * sorted = new std::deque<std::pair<int, int> >;
		(*sorted).push_back(pair[begin]);
		return sorted;
	}
	std::deque<std::pair<int, int> > *arr_1 = NULL, *arr_2 = NULL, *sorted = NULL;
	try {
		arr_1 = rec_sort_hight_elem(pair, begin, begin + (end - begin) / 2);
		arr_2 = rec_sort_hight_elem(pair, begin + (end - begin) / 2 + 1, end);
		std::deque<std::pair<int, int> > * sorted = new std::deque<std::pair<int, int> >((*arr_1).size() + (*arr_2).size()) ;
		std::merge((*arr_1).begin(), (*arr_1).end(), (*arr_2).begin(), (*arr_2).end(), (*sorted).begin());
		delete arr_1;
		delete arr_2;
		return (sorted);
	}
	catch (std::bad_alloc const & e) {
		delete arr_1;
		delete arr_2;
		delete sorted;
		throw ;
	}
}

void	PmergeMe::dichotomic_insertion(std::deque<int> & sorted, std::deque< std::pair<int, int> > * pair, size_t size) {
	
	size_t i = 1;
	std::deque<int>::iterator it;
	size_t j_next ;
	size_t j = 1;
	
	while (1)
	{
		j_next = jacobsthal_suit(1);
		if (j_next >= size)
			j_next = size;
		if (j == j_next)
			break;
		it = std::upper_bound(sorted.begin(), sorted.begin() + j_next + i, (*pair)[j_next - 1].second);
		sorted.insert(it, (*pair)[j_next - 1].second);
		i++;
		j++;
		while (j < j_next) {
			it = std::upper_bound(sorted.begin(), sorted.begin() + j + i, (*pair)[j - 1].second);
			sorted.insert(it, (*pair)[j - 1].second);
			i++;
			j++;
		}
		if (j_next == size)
			break;
	}
}

void	PmergeMe::to_deque() {
	
	std::deque< int > to_sort;
	size_t				size;
	std::deque<std::pair<int, int> > * sorted_pair = NULL;
	
	try {
		parse_nb(to_sort);
		print_container< std::deque<int> >(to_sort, "Before :");
	
		/* Create array of pair with elements' pair sorted */
		size = to_sort.size() / 2;
		std::deque<std::pair<int, int> > pair(size);
		// std::cout << "to_sort.size() = " << to_sort.size() << std::endl;
		make_pair(pair, to_sort);
		
		/* Sort pair regards to highest elements */
		sorted_pair = rec_sort_hight_elem(pair, 0, size - 1);
		
		/* Push highest elements sorted to deque */
		std::deque<int> sorted;
		for (std::deque< std::pair<int, int> >::iterator it = (*sorted_pair).begin(); it != (*sorted_pair).end(); it++)
			sorted.push_back((*it).first);
		
		/* Insert the smallest element of thefirst pair */
		sorted.insert(sorted.begin(), (*(*sorted_pair).begin()).second);
		
		// /* Insert the smallest elems of pair */
		this->dichotomic_insertion(sorted, sorted_pair, size);
		delete sorted_pair;
		sorted_pair = NULL;
		
		if (this->_parity == 1)
		{
			std::deque< int >::iterator itt = std::upper_bound(sorted.begin(), sorted.end(), this->_left);
			sorted.insert(itt, this->_left);
		}
		print_container< std::deque<int> >(sorted, "After :");
		// std::cout << "to_sort.size() = " << sorted.size() << std::endl;
	}
	catch (std::bad_alloc const & e) {
		delete sorted_pair;
		throw ; }
	catch (std::out_of_range const & e) {
		delete sorted_pair;
		throw ; }
	catch (std::length_error const & e) {
		delete sorted_pair;
		throw ; }
	catch (std::exception const & e) {
		delete sorted_pair;
		throw ; }
}
